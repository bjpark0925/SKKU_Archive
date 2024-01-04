#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>    //fork()
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait()

# define NUM 10

void child_process(int i){
    printf("process pid-- %d , %d'st child process started\n", getpid(), i + 1);
    sleep(3);
    printf("process pid-- %d , %d'st child process executing\n", getpid(), i + 1);
    sleep(3);
    printf("process pid-- %d , %d'st child process ended\n", getpid(), i + 1);
    exit(0);
}

int main(){
    pid_t pid[NUM];

    for(int i = 0; i < NUM; i++){
        pid[i] = fork();

        if (pid[i]<0){ // error case
            printf("Error!\n");
            return -1;
        }
        else if(pid[i] == 0){ // child process
            child_process(i);
        }
        else // parent process
            printf("process pid-- %d , parent process executing\n", getpid());
    }

    for(int i = 0; i < NUM; i++){ // wait for 10 processes to end
        wait(NULL);
    }
    printf("process pid-- %d , parent process ended\n", getpid());
    return 0;
}