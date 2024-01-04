/*message passing 방식
커널이 queue를 통해 중계하는 메시지 전달 방식(일반적으로 두 프로세스 사이에서 수행)
목적지를 명시하는 direct방식과 메일박스명을 명시하는 indirect방식으로 나뉨
int msgget(key_t key, int msgflg): 메시지 큐를 생성함(msqid(아이디) 리턴)
key: 메시지의 식별번호, msgflg: key에 해당하는 메시지큐가 있다면 어떻게 행동할지
메시지 데이터의 구조 (*msgp의 자료형)
struct{
long data_type;
char data_buff[BUFF_SIZE];
}
또는
struct{
long data_type;
int data_num;
char data_buff[BUFF_SIZE];
}
또는
struct{
long data_type;
int data_num;
}
int msgsnd(int msqid, void *msgp, size_t msgsz, int msgflg): 메시지 큐에 메시지를 보냄
성공시 0리턴, 실패시 -1리턴
msqid: 메시지 아이디
msgp: 전송할 자료
msgsz: 메시지 데이터의 크기
int msgrcv(int msqid, void* msgp, size_t msgsz, long msgtyp, int msgflg): 메시지 큐에서 메시지를 받음
성공시 0리턴, 실패시 -1리턴
msgp: 수신할 데이터를 저장할 버퍼
msgtyp: 수신할 메시지 타입(0: 아무 메시지나 수신, 양수: msgtyp이 일치하는 메시지 수신, 음수: 절댓값보다 작은 타입 수신)
msgflg로 IPC_NOWAIT가 설정되어 있으면, 수신할 메시지가 없다면 -1을 리턴함
msgflg로 IPC_NOWAIT가 설정되어 있지 않으면, 수신할 때까지 block됨
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/msg.h>   //message passing
#include <sys/types.h> //pid_t
#include <unistd.h>    //fork()
#include <signal.h>

struct msgbuf
{
    long mtype;
    int mdata;
};

int main()
{
    key_t key = 1234;
    int msqid = msgget(key, 0666 | IPC_CREAT); // 플래그 IPC_CREAT은 메모리 생성
    if (msqid == -1)
    {
        perror("msgget failed");
        exit(1);
    }

    pid_t pid = fork();
    if (pid == 0)
    { // child process 읽기
        struct msgbuf buf;
        while (1)
        {
            if (msgrcv(msqid, &buf, sizeof(int), 1, IPC_NOWAIT) != -1)
            {
                printf("Child reads: %d\n", buf.mdata);
            }
            sleep(1);
        }
    }
    else if (pid > 0)
    { // parent process 쓰기
        struct msgbuf buf;
        buf.mtype = 1;
        for (int i = 0; i < 10; i++)
        {
            buf.mdata = i;
            printf("Parent changed data to %d\n", buf.mdata);
            msgsnd(msqid, &buf, sizeof(int), IPC_CREAT);
            sleep(1);
        }
        kill(pid, SIGKILL);
        msgctl(msqid, IPC_RMID, NULL);
        printf("Parent pocess completed.\n");
    }
    else
    {
        perror("fork failed");
        exit(1);
    }

    return 0;
}