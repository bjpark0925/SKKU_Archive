#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
// for Message queue
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define KEY_NUM 2357
#define BUFFER_SIZE 1024

void msgqueue_print(int msqid);

typedef struct { // Message buffer structure
  long msgtype; // Message type, must be > 0 with 'long' data type
  int value;
  char buf[BUFFER_SIZE]; // Message data to push in queue
} msgbuf;

int main() {
    int cnt = 10;
    int msqid; // Message queue ID
    msgbuf msg;
    msg.msgtype = 1;

    msqid = msgget((key_t) KEY_NUM, IPC_CREAT|0666); // Create Message (message queue key, message flag)

    if (msqid == -1) {
        printf("Message Get Failed!\n");
        exit(0);
    }
    
    printf("Before Message Sending\n");
    msgqueue_print(msqid);

    for (int i=0;i<cnt;i++)
    {
        msg.value = i;
        strcpy(msg.buf, "I love OS");

        if (msgsnd(msqid, &msg, sizeof(msg), IPC_NOWAIT) == -1) { // IPC_NOWAIT flag: if no more queue space, fail instead of blocking
            printf("Message Sending Failed!\n");
            exit(0);
        }
        
        printf("value: %d     message: %s\n", msg.value, msg.buf);
        sleep(1);
    }

    printf("After Message Sending\n");
    msgqueue_print(msqid);
    exit(0);
}

void msgqueue_print(int msqid)
{
    struct msqid_ds m_stat;
    printf("========== messege queue info =============\n");
    //msgctl 함수: message queue 상태 정보 획득, 제한 변경, queue 제거 용도
    if(msgctl(msqid,IPC_STAT,&m_stat)==-1)
    {
            printf("msgctl failed");
            exit(0);
    }
    printf(" message queue info \n");
    printf(" msg_qnum : %ld\n",m_stat.msg_qnum); // queue number
    // lspid: 마지막으로 송신한 pid, stime: message send time
    printf(" Last send by process %d at %ld\n",m_stat.msg_lspid, m_stat.msg_stime);
    // lrpid: 마지막으로 수신한 pid, rtime: message receive time
    printf(" Receiving list by %d at %ld\n",m_stat.msg_lrpid, m_stat.msg_rtime); // 

    printf("========== messege queue info end =============\n");
}