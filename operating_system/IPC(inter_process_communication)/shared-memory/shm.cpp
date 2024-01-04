#include <iostream>
#include <sys/wait.h> //wait()
#include <sys/ipc.h>
#include <sys/shm.h> //shared memory
#include <string.h>
#include <unistd.h>
 
#define  KEY_NUM   1234
#define  MEM_SIZE  4096

using namespace std;
 
int shmid;
static int SharedMemoryCreate();
static int SharedMemoryWrite(const char* msg);
static int SharedMemoryRead();
static int SharedMemoryFree();
 
int main(int argc, char *argv[])
{
    pid_t pid;
    cout<<"Parent PID: "<<getpid()<<endl;
    
    SharedMemoryCreate(); // 공유 메모리 생성

    pid = fork();

    if (pid<0)
    {
        cerr<<"Error: Fork failed"<<endl;
        return 1;
    }
    else if (pid==0) // child(write)
    {
        const char* message1="Operating System";
        cout<<"Child1 PID: "<<getpid()<<endl; //child process의 PID 출력
        SharedMemoryWrite(message1);// 공유 메모리에 write
        exit(0); // child process 종료
    }
    else // parent
    {
        pid = fork();
        if (pid<0)
        {
            cerr<<"Error: Fork failed"<<endl;
            return 1;
        }
        else if (pid==0) // child(read then write)
        {
            const char* message2="SKKU COMEDU";
            cout<<"Child2 PID: "<<getpid()<<endl; //child process의 PID 출력
            SharedMemoryRead(); // 공유 메모리로부터 read
            SharedMemoryWrite(message2);// 공유 메모리에 write
            exit(0); // child process 종료
        }
        else // parent(read)
        {
            wait(0);
            SharedMemoryRead();
            cout<<"Parent Read complete"<<endl;
        }
    }
    SharedMemoryFree();

    return 0;
}
 
static int SharedMemoryCreate()
{
    // shmget 함수: 커널에 공유 메모리 공간 요청 위한 시스템 콜
    // KEY_NUM은 공유 메모리를 식별하는 키, MEM_SIZE는 공유 메모리 크기
    // 플래그 IPC_CREAT은 공유 메모리 생성
    // IPC_EXCL은 이미 해당 키로 공유 메모리가 존재하면 실패하도록, 0666은 권한 설정
    if((shmid = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT| IPC_EXCL | 0666)) == -1)
    {
        printf("Shared memory already exist.");
        return 1;
    }
    
    // shmid = shmget((key_t)KEY_NUM, MEM_SIZE, IPC_CREAT| 0666);
    if (shmid == -1)
    {
        cerr<<"Shared memory create fail"<<endl;
        return 1;
    }
    else
    {
        cout<<"Shared memory created succesfully"<<endl;
    }
    
    return 0;
}
 
static int SharedMemoryWrite(const char* msg)
{
    void *shmaddr;
    int size=strlen(msg);
    if(size > MEM_SIZE)
    {
        printf("Shared memory size over");
        return 1;
    }
    // shmat 함수: 생성된 공유 메모리 공간에 접근할 수 있는 '식별자'를 얻음
    if((shmaddr = shmat(shmid, (void *)0, 0)) == (void *)-1) 
    {
        perror("Shmat failed");
        return 1;
    }
    
    strcpy((char *)shmaddr, msg);
    
    // shmdt 함수: 공유 메모리를 호출 프로레스의 메모리 영역에서 분리
    if(shmdt(shmaddr) == -1) 
    {
        perror("Shmdt failed");
        return 1;
    }
    return 0;
}
 
static int SharedMemoryRead()
{
    void *shmaddr;
    
    if((shmaddr = shmat(shmid, (void *)0, 0)) == (void *)-1)
    {
        perror("Shmat failed");
        return 1;
    }
    
    cout<<"Message from shared memory: "<<(char*)shmaddr<<endl;
    
    if(shmdt(shmaddr) == -1)
    {
        perror("Shmdt failed");
        return 1;
    }
    return 0;
}
 
static int SharedMemoryFree()
{
    // shmctl 함수: 공유 메모리 삭제 등 작업
    shmctl(shmid, IPC_RMID, (struct shmid_ds *)NULL);
    
    cout<<"Shared memory end"<<endl;
    return 0;
}