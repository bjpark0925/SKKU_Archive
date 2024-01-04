#include <iostream>
#include <cstring> // memset
#include <queue>
#include <sys/ipc.h>
#include <sys/msg.h>   //message passing
#include <sys/types.h> //pid_t
#include <sys/time.h>
#include <unistd.h> //fork()
#include <signal.h> //signal()

using namespace std;

#define NUM_CHILD 10
#define TIME_QUANTUM 160 // mili-second
#define TICK 20          // mili-second
#define KEY_NUM 1234     // 1개의 message queue만 사용

/*
IPC message 사용처
child 기준: <1. 자신의 init 정보 송신> <2. tick마다 자신의 정보 수신> <3. terminate 시 parent에게 알림>
parent 기준: <1. child의 init 또는 terminate 정보 수신> <2. tick마다 child 정보 송신>
*/
typedef struct _process
{
    int pid;
    int quantum;   // time quantum
    int cpu_burst; // cpu burst time
    int io_burst;  // io burst time(미리 정해짐)
    int remainIO;  // wait queue에서 계속 감소시켜 0되면 ready queue 가도록
    int io_start;  // io 시작 시간
    int is_io;     // io 당첨 여부
    int state;     // 0: ready, 1: running, 2: waiting, 3: terminated
    int arrival;   // first ready queue arrival time
    int response;  // first running time - arrival time
    int wait;      // ready queue에서 기다린 시간
} process;

// 메인에서 memset(&analyzeData, 0, sizeof(analyzeData));로 멤버 변수 0으로 초기화 필요
typedef struct _analyzeData
{
    int context_switching;
    int response_time;
    int waiting_time;
    int turnaround_time; // terminated time - arrival time
    int count;           // for average
} analyzeData;

typedef struct _msgbuf
{
    long mtype;
    process mprocess;
} MsgBuf;

// 전역변수
int msqid;
int terminate_count = 0; // 종료된 child 수
int quantum_count = 0;
int tick_count = 0;
bool is_sigint = true;
long long start; // 시작 시간
analyzeData data;
queue<process> ready_queue;
queue<process> io_queue;

void init_process(process &p)
{
    p.pid = getpid();
    p.quantum = -1; // parent가 ipc 메시지 전달하기 전까진 time quantum 정보 모름

    // cpu burst 랜덤으로 설정 +  io burst, io start 랜덤으로 설정(option3)
    struct timeval time; // 시간 표현 구조체 in C
    gettimeofday(&time, NULL);
    srand(time.tv_usec);                                      // 난수 발생기의 시드(seed)를 현재 시각 마이크로초로 설정
    p.cpu_burst = 6000 + (rand() % (2000 / TICK + 1)) * TICK; // 6초(6000ms)~8초(8000ms), TICK(20ms) 간격
    p.io_burst = 200 + (rand() % (120 / TICK + 1)) * TICK;    // 200ms~320ms, TICK(20ms) 간격
    p.remainIO = 0;
    p.io_start = TICK + (rand() % (TIME_QUANTUM / TICK - 1)) * TICK; // TICK(20ms)부터 time quantum 끝나기 전까지 랜덤, TICK(20ms) 간격
    p.is_io = -1;
    p.state = 0;
    p.arrival = 0;
    p.response = -1; // running 전까진 response time 모름
    p.wait = 0;
}

void printData(analyzeData &data)
{
    // 파일을 열어서 기록
    FILE *outputFile = fopen("schedule_dump.txt", "a"); // "a": 파일 끝에 추가 모드
    if (outputFile == NULL)
    {
        perror("Error: Could not open the file 'schedule_dump.txt' for writing.");
        exit(1);
    }

    fprintf(outputFile, "total context switch: %d\n", data.context_switching);
    if (data.count != 0)
    {
        fprintf(outputFile, "average response time: %dms\n", data.response_time / data.count);
        fprintf(outputFile, "average waiting time: %dms\n", data.waiting_time / data.count);
        fprintf(outputFile, "average turnaround time: %dms\n", data.turnaround_time / data.count);
        fprintf(outputFile, "total number of process terminated: %d\n", data.count);
    }
    else
    {
        fprintf(outputFile, "there is no terminated process\n");
    }

    // 파일 닫기
    fclose(outputFile);
}

void exitProgram(int sig)
{
    // 파일을 열어서 기록
    FILE *outputFile = fopen("schedule_dump.txt", "a"); // "a": 파일 끝에 추가 모드
    if (outputFile == NULL)
    {
        perror("Error: Could not open the file 'schedule_dump.txt' for writing.");
        exit(1);
    }

    fprintf(outputFile, "\n===============Exit Program===============\n");
    // 종료 시간
    struct timeval time;
    gettimeofday(&time, NULL);
    long long end = time.tv_sec * 1000 + time.tv_usec / 1000; // 밀리초 계산

    // Ctrl+C 입력 시 수행: ready queue와 waiting queue clear
    if (is_sigint)
    {
        fprintf(outputFile, "Ctrl+C pressed\n");

        // ready queue clear
        while (!ready_queue.empty())
        {
            process temp = ready_queue.front();
            ready_queue.pop();
            kill(temp.pid, SIGKILL);
        }
        fprintf(outputFile, "ready queue clear complete\n");
        // io queue clear
        while (!io_queue.empty())
        {
            process temp = io_queue.front();
            io_queue.pop();
            kill(temp.pid, SIGKILL);
        }
        fprintf(outputFile, "io queue clear complete\n");
    }

    // 메시지 큐 삭제
    if (msgctl(msqid, IPC_RMID, NULL) == -1)
    {
        perror("msgctl failed");
        exit(1);
    }
    else
    {
        fprintf(outputFile, "[msqid %d] msgctl(remove) success!\n", msqid);
    }

    fprintf(outputFile, "===============Information================\n");
    fprintf(outputFile, "running time: %llds\n", (end - start) / 1000);

    // 파일 닫기
    fclose(outputFile);

    // 결과 출력
    printData(data);

    exit(0);
}

void schedule(int sig)
{
    // 파일을 열어서 기록
    FILE *outputFile = fopen("schedule_dump.txt", "a"); // "a": 파일 끝에 추가 모드
    if (outputFile == NULL)
    {
        perror("Error: Could not open the file 'schedule_dump.txt' for writing.");
        exit(1);
    }

    struct timeval time;

    // 종료 조건
    if (terminate_count == NUM_CHILD)
    {
        is_sigint = false;
        exitProgram(0);
    }

    // 메시지 수신: child의 <init> or <terminate>정보(child -> parent)
    MsgBuf msg;
    if (msgrcv(msqid, &msg, sizeof(process), 0, IPC_NOWAIT) > 0)
    {
        if (msg.mprocess.state == 0)
        {
            gettimeofday(&time, NULL);
            long long now = time.tv_sec * 1000 + time.tv_usec / 1000; // 밀리초 계산

            process my_p = msg.mprocess;
            my_p.arrival = now - start;
            // ready queue에 넣기
            ready_queue.push(my_p);
        }
        else if (msg.mprocess.state == 3) // terminated
        {
            terminate_count++;
            process my_p = msg.mprocess;

            gettimeofday(&time, NULL);
            long long now = time.tv_sec * 1000 + time.tv_usec / 1000;
            data.response_time += my_p.response;
            data.waiting_time += my_p.wait;
            data.turnaround_time += now - start - my_p.arrival;
            data.count++;
            fprintf(outputFile, "terminate child [PID %d]\n", my_p.pid);
            kill(my_p.pid, SIGKILL);
        }
    }

    // ready queue 관련
    if (!ready_queue.empty()) // ready queue에 process가 있으면
    {
        // front를 제외한 ready queue의 모든 process의 wait 증가
        for (int i = 0; i < ready_queue.size(); i++)
        {
            if (i == 0)
            {
                ready_queue.push(ready_queue.front());
                ready_queue.pop();
                continue;
            }
            ready_queue.front().wait += TICK;
            ready_queue.push(ready_queue.front());
            ready_queue.pop();
        }

        // ready queue의 front를 running 상태로
        if (ready_queue.front().quantum == -1)
        {
            ready_queue.front().quantum = TIME_QUANTUM;
        }
        ready_queue.front().state = 1;
        ready_queue.front().cpu_burst -= TICK;

        // 첫 running만 response time 기록
        if (ready_queue.front().response == -1)
        {
            gettimeofday(&time, NULL);
            long long now = time.tv_sec * 1000 + time.tv_usec / 1000;
            ready_queue.front().response = now - start - ready_queue.front().arrival;
        }

        // 25% 확률로 io 당첨
        if (ready_queue.front().is_io == -1)
        {
            gettimeofday(&time, NULL);
            srand(time.tv_usec);
            if (rand() % 4 == 0)
            {
                ready_queue.front().is_io = 1;
            }
            else
            {
                ready_queue.front().is_io = 0;
            }
        }

        msg.mtype = 2 * ready_queue.front().pid; // parent가 보내는 mtype은 2*getpid()
        msg.mprocess = ready_queue.front();

        // io 당첨 시
        if (ready_queue.front().is_io == 1)
        {
            // front가 자리를 옮겨야 할 때
            if (ready_queue.front().cpu_burst <= 0 || quantum_count >= ready_queue.front().io_start)
            {
                data.context_switching++;
                if (ready_queue.front().cpu_burst <= 0)
                {
                    ready_queue.front().state = 3; // terminated
                }
                else // (quantum_count == ready_queue.front()->io_start)
                {
                    // io queue로 넘어감
                    ready_queue.front().state = 2;
                    ready_queue.front().remainIO = ready_queue.front().io_burst;
                    io_queue.push(ready_queue.front());
                }
                msg.mprocess = ready_queue.front();
                ready_queue.pop();

                quantum_count = 0; // 다음 process running 위해 0으로 초기화
            }
        }
        else // 75% 확률로 io 당첨 안된 경우
        {
            // front가 자리를 옮겨야 할 때
            if (ready_queue.front().cpu_burst <= 0 || quantum_count >= ready_queue.front().quantum)
            {
                data.context_switching++;
                if (ready_queue.front().cpu_burst <= 0)
                {
                    ready_queue.front().state = 3; // terminated
                }
                else // (quantum_count == TIME_QUANTUM)
                {
                    // ready queue로 넘어감
                    ready_queue.front().state = 0;
                    ready_queue.front().is_io = -1;
                    ready_queue.push(ready_queue.front());
                }
                msg.mprocess = ready_queue.front();
                ready_queue.pop();

                quantum_count = 0; // 다음 process running 위해 0으로 초기화
            }
        }
        // msgsnd
        if (msgsnd(msqid, &msg, sizeof(process), 0) == -1)
        {
            fprintf(outputFile, "parent's msgsnd failed1\n");
            exit(1);
        }
    }
    else // ready queue에 process가 없으면
    {
        quantum_count = 0;
    }

    // io queue 관련
    if (!io_queue.empty()) // io queue에 process가 있으면
    {
        io_queue.front().remainIO -= TICK;

        msg.mtype = 2 * io_queue.front().pid;
        msg.mprocess = io_queue.front();

        // io queue의 front가 자리를 옮겨야 할 때
        if (io_queue.front().remainIO <= 0)
        {
            io_queue.front().state = 0;
            io_queue.front().is_io = -1;
            ready_queue.push(io_queue.front());

            msg.mprocess = io_queue.front();

            io_queue.pop();
        }
        // msgsnd
        if (msgsnd(msqid, &msg, sizeof(process), 0) == -1)
        {
            fprintf(outputFile, "parent's msgsnd failed2\n");
            exit(1);
        }
    }

    // 출력
    fprintf(outputFile, "===============tick %d===============\n", tick_count);
    fprintf(outputFile, "quantum count: %d\n", quantum_count);
    if (!ready_queue.empty()) // ready queue에 process가 있으면
    {
        fprintf(outputFile, "Running: [pid: %d, quantum: %d, cpu burst: %d, io burst: %d, remainIO: %d, io start: %d, is_io: %d, state: %d, arrival: %d, response: %d, wait: %d]\n",
                ready_queue.front().pid, ready_queue.front().quantum, ready_queue.front().cpu_burst, ready_queue.front().io_burst, ready_queue.front().remainIO, ready_queue.front().io_start, ready_queue.front().is_io, ready_queue.front().state, ready_queue.front().arrival, ready_queue.front().response, ready_queue.front().wait);
    }
    fprintf(outputFile, "Ready Queue: ");
    if (!ready_queue.empty())
    {
        queue<process> temp_queue = ready_queue; // 복사본으로 순회
        while (!temp_queue.empty())
        {
            fprintf(outputFile, "[PID: %d, CPU Burst: %d]", temp_queue.front().pid, temp_queue.front().cpu_burst);
            temp_queue.pop();
        }
    }
    fprintf(outputFile, "\n");

    fprintf(outputFile, "IO Queue: ");
    queue<process> temp_queue = io_queue;
    while (!temp_queue.empty())
    {
        fprintf(outputFile, "[PID: %d, IO Burst: %d, CPU Burst: %d]", temp_queue.front().pid, temp_queue.front().remainIO, temp_queue.front().cpu_burst);
        temp_queue.pop();
    }
    fprintf(outputFile, "\n");

    // 파일 닫기
    fclose(outputFile);

    quantum_count += TICK;
    tick_count += TICK;
}

int main()
{
    // 파일 초기화
    FILE *outputFile = fopen("schedule_dump.txt", "w");
    if (outputFile == NULL)
    {
        perror("Error: Could not open the file 'schedule_dump.txt' for writing.");
        exit(1);
    }

    // 메시지 큐 생성
    msqid = msgget(KEY_NUM, IPC_CREAT | 0666);
    if (msqid == -1)
    {
        perror("msgget failed");
        exit(1);
    }
    else
    {
        printf("[msqid %d] msgget success!\n", msqid);
    }

    // 시작 시간
    struct timeval time; // 시간 표현 구조체 in C
    gettimeofday(&time, NULL);
    start = time.tv_sec * 1000 + time.tv_usec / 1000; // 밀리초 계산

    pid_t parent = getpid();
    pid_t pid;
    for (int i = 0; i < NUM_CHILD; i++)
    {
        if (getpid() == parent)
            pid = fork(); // child process 생성
    }

    if (pid < 0) // error case
    {
        fprintf(outputFile, "fork failed\n");
        return -1;
    }
    else if (pid == 0) // child process
    {
        printf("child process created [PID %d]\n", getpid());
        process my_p;
        init_process(my_p);

        // parent에게 msgsnd로 child 정보 전달
        MsgBuf msg;
        msg.mtype = getpid(); // parent가 어느 child인지 구분하도록
        msg.mprocess = my_p;

        // 메시지 송신: child 초기 정보(child -> parent)
        if (msgsnd(msqid, &msg, sizeof(process), IPC_NOWAIT) == -1) // IPC_NOWAIT flag: if no more queue space, fail instead of blocking
        {
            perror("child's msgsnd failed");
            exit(1);
        }
        else
        {
            printf("child process's init msgsnd complete [PID %d]\n", getpid());
        }

        // 메시지 수신: tick마다 parent가 child에게 보낸 것
        while (1)
        {
            // child는 msgtyp이 2*getpid()인 메시지만 수신(parent는 msgtyp이 getpid()인 메시지만)
            if (msgrcv(msqid, &msg, sizeof(process), 2 * getpid(), 0) == -1) // 0: blocking(수신할 때까지)
            {
                perror("child's msgrcv failed");
                exit(1);
            }
            my_p = msg.mprocess;

            // child terminated
            if (my_p.state == 3)
            {
                msg.mtype = my_p.pid;
                msg.mprocess = my_p;
                if (msgsnd(msqid, &msg, sizeof(process), 0) == -1)
                {
                    printf("child's msgsnd failed in terminating\n");
                    exit(1);
                }
                break;
            }
        }
    }
    else // parent process
    {
        printf("parent process executing [PID %d]\n", getpid());
        memset(&data, 0, sizeof(analyzeData));

        // 특정 시그널이 발생했을 때 실행할 핸들러 함수를 설정
        struct sigaction sa1, sa2;    // signal 함수 대신 sigaction 사용
        struct itimerval timer;       // 시간 간격마다 주기적으로 발생하는 SIGVTALRM 시그널을 위한 구조체
        memset(&sa1, 0, sizeof(sa1)); // sa1 초기화
        memset(&sa2, 0, sizeof(sa2));
        sa1.sa_handler = &schedule; // schedule 함수를 핸들러로 설정
        sa2.sa_handler = &exitProgram;
        sigaction(SIGVTALRM, &sa1, NULL); // SIGVTALRM 시그널: 타이머 만료 시 발생
        sigaction(SIGINT, &sa2, NULL);    // SIGINT 시그널: Ctrl+C 입력 시 발생

        // TICK마다 만료되는 타이머 설정
        timer.it_interval.tv_sec = 0;
        timer.it_interval.tv_usec = TICK * 1000; // 마이크로초를 TICKms로
        // timer 초기값
        timer.it_value.tv_sec = 0;
        timer.it_value.tv_usec = TICK * 1000;

        setitimer(ITIMER_VIRTUAL, &timer, NULL);
        // 무한 루프. 타이머에 의해 주기적으로 SIGVTALRM 시그널이 발생하며, 이를 처리하는 핸들러가 실행됨
        while (1)
            ;
    }

    // 파일 닫기
    fclose(outputFile);

    return 0;
}