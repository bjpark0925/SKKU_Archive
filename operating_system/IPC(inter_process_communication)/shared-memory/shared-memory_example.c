/*shared memory 방식
여러 프로세스가 함께 사용하는 메모리
int shmget(key_t key, int size, int shmflag): 공유 메모리 공간을 만듦
shmid(식별자)를 반환 (실패 시 -1 반환)
key: 공유 메모리의 식별번호, size: 공유 메모리의 크기, shmflag: key에 해당하는 공유 메모리가 이미 있을 때 동작 옵션
void* shmat(int shmid, void* shmaddr, int shmflag): 공유 메모리를 프로세스 안에 첨부함
(해당 공간의 포인터 반환, 실패 시 -1 반환)
int shmdt(void* shmaddr): 공유 메모리를 프로세스에서 분리함
프로세스가 작업을 끝내고 더 이상 메모리 공유가 필요 없을 때, 공유메모리와 연결된 프로세스 내부의 가상 메모리 연결 해제
int shmctl(int shmid, int cmd, struct shmid_ds* buf): 공유 메모리의 정보를 확인/변경/제거
shmid: 제어할 공유메모리 아이디, cmd: 수행할 명령, buf: 공유 메모리 정보가 나타나는 버퍼에 대한 포인터
함수 리턴값 아니라 buf로 전달받는 방법 term 때 사용 가능
https://badayak.com/entry/C%EC%96%B8%EC%96%B4-%EA%B3%B5%EC%9C%A0-%EB%A9%94%EB%AA%A8%EB%A6%AC-%EC%A0%95%EB%B3%B4-%ED%99%95%EC%9D%B8%C2%B7%EB%B3%80%EA%B2%BD%C2%B7%EC%A0%9C%EA%B1%B0-%ED%95%A8%EC%88%98-shmctl
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>   //shared memory
#include <sys/types.h> //pid_t
#include <unistd.h>    //fork()
#include <signal.h>

int main()
{
    key_t key = 1234;
    // shmget을 통해 공유 메모리 세그멘트를 생성하거나 접근
    int shmid = shmget(key, sizeof(int), 0666 | IPC_CREAT);
    if (shmid == -1)
    {
        perror("shmget failed");
        exit(1);
    }

    int *data = (int *)shmat(shmid, (void *)0, 0); // shmat을 사용하여 공유메모리 세그멘트를 현재 프로세스의 주소 공간에 연결
    if (data == (int *)-1)
    {
        perror("shmat failed");
        exit(1);
    }
    *data = 0;

    pid_t pid = fork();
    if (pid == 0)
    { // 자식 프로세스일 경우
        while (1)
        {
            printf("Child reads: %d\n", *data);
            sleep(1);
        }
    }
    else if (pid > 0)
    {
        for (int i = 0; i < 10; i++)
        {
            (*data)++;
            printf("Parent changed data to %d\n", (*data));
            sleep(1);
        }
        kill(pid, SIGKILL);
        shmdt(data);
        shmctl(shmid, IPC_RMID, NULL);
        printf("Parent process completed.\n");
    }
    else
    {
        perror("fork failed");
        exit(1);
    }

    return 0;
}