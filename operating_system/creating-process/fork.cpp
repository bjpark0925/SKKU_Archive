#include <iostream>
#include <unistd.h> //fork()
#include <sys/types.h> //pid_t
#include <sys/wait.h> //wait()
using namespace std;

int main()
{
    pid_t pid;
    cout<<"Parent PID: "<<getpid()<<endl;
    
    for (int i=0;i<10;i++)
    {
        pid=fork(); // child process 생성

        //pid<0이면 에러, pid==0이면 자식, pid>0이면 부모(반환값으로 자식 pid 받음)
        if (pid<0)
        {
            cerr<<"Error: Fork failed"<<endl;
            return 1;
        }
        else if (pid==0)
        {
            cout<<"Child PID: "<<getpid()<<endl; //child process의 PID 출력
            exit(0); // 각 child process 종료
        }
    }

    sleep(1); // child가 pid를 모두 출력할 때까지 기다림
    
    for (int i=0;i<10;i++)
    {
        int status;
        pid_t terminated_child_pid=wait(&status); //wait()로 종료된 child process의 pid 값 받아옴
        cout<<"Child process PID "<<terminated_child_pid<<" terminated"<<endl;
    }

    cout<<"Parent process PID "<<getpid()<<" terminated"<<endl;

    return 0;
}