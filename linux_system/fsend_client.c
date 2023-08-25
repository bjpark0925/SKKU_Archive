#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <unistd.h> 
#include <arpa/inet.h> 
#include <sys/socket.h> 

#define BUFSIZE 1460 

void error_handling(char* message);

int main(int argc, char** argv)
{
    int clnt_sock;
    FILE* fp;

    struct sockaddr_in serv_addr;

    char buf[BUFSIZE];
    char client_message[30] = "Hello Server"; // client가 server에 보내는 메시지
    char debug_message1[30] = "Different Size";
    char debug_message2[30] = "Same Size";
    char server_message[30]; // server가 client에 보낸 메시지를 저장

    int read_cnt;
    int filesize = 0;
    int recvsize;
    

    if (argc != 3) {
        printf("Error : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    //소켓 생성
    clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (clnt_sock == -1)
        error_handling("socket() error");

    //serv_addr 주소 지정
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    //connect
    if (connect(clnt_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error!");

    //데이터 주고받기

    //1. client가 "Hello Server"메시지 보내기
    write(clnt_sock, client_message, sizeof(client_message));

    //2. 파일 받기

    //추후 debug를 위해 원본 파일 사이즈 받기
    read(clnt_sock, &filesize, sizeof(filesize));

    //파일 열기(파일이 존재하지 않으므로 빈 파일 새로 생성됨)
    fp = fopen("receive.mp4", "wb"); // 이진 쓰기 모드
    if (fp == NULL)
        error_handling("file open error");

    //파일 수신
    while ((read_cnt = read(clnt_sock, buf, BUFSIZE)) != 0)
    {
        fwrite((void*)buf, 1, read_cnt, fp);
    }

    //3. 받은 파일과 원본 파일 사이즈 비교
    fseek(fp, 0, SEEK_END);
    recvsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    //4. 사이즈 비교 후, 알맞은 메시지 보내기
    if (filesize != recvsize)
        write(clnt_sock, debug_message1, sizeof(debug_message1));
    else
        write(clnt_sock, debug_message2, sizeof(debug_message2));

    //4. Good bye 메시지 받기
    if (read(clnt_sock, server_message, sizeof(server_message) - 1) == -1)
        error_handling("read error!");
    printf("Message from server: %s \n", server_message);

    //파일 및 소켓 닫기
    fclose(fp);
    close(clnt_sock);
    return 0;
}

void error_handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}