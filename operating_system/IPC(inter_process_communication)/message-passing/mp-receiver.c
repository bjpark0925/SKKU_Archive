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

typedef struct {
    long msgtype;
    int value;
    char buf[BUFFER_SIZE];
} msgbuf;

int main() {
    int msqid;
    msgbuf msg;
    msg.msgtype = 1;
    
    msqid = msgget((key_t) KEY_NUM, IPC_CREAT|0666); // Create Message (message queue key, message flag)
    
    if (msqid == -1) {
        printf("Message Get Failed!\n");
        exit(0);
    }

    printf("Before Message Receiving\n");
    msgqueue_print(msqid);
    
    while (1) {
        if (msgrcv(msqid, &msg, sizeof(msg), 1, 0) == -1) {
            printf("Message Receiving Finished!\n");
            break;
        }
        
        printf("value: %d     message: %s\n", msg.value, msg.buf);
    }

    printf("Message Receiving Finished!\n");
    printf("After Message Sending\n");
    msgqueue_print(msqid);

    //메시지 큐 삭제
    if(msgctl(msqid,IPC_RMID,NULL)==-1)
    {
        printf("msgctl failed\n");
        exit(0);
    }
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