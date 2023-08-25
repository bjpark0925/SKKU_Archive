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
    int serv_sock;
    int clnt_sock;
    FILE* fp; // 파일 포인터(.mp4파일을 가리킴)

    struct sockaddr_in serv_addr;
    struct sockaddr_in clnt_addr;
    socklen_t clnt_addr_size;

    char buf[BUFSIZE];
    char cbuf[BUFSIZE];
    char client_message[30];
    char server_message[] = "Good Bye Client";

    int read_cnt;
    int filesize;

    if (argc != 2) {
        printf("Error : %s <port>\n", argv[0]);
        exit(1);
    }

    //소켓 생성
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket error");

    //serv_addr 주소 지정
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(atoi(argv[1]));

    //bind
    if (bind(serv_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
        error_handling("bind error");

    //listen
    if (listen(serv_sock, 2) == -1)
        error_handling("listen error");

    //accept
    clnt_addr_size = sizeof(clnt_addr);
    clnt_sock = accept(serv_sock, (struct sockaddr*) & clnt_addr, &clnt_addr_size);
    if (clnt_sock == -1)
        error_handling("accept error");

    //데이터 주고받기

    //1. client가 보낸 메시지 받기
    if (read(clnt_sock, client_message, sizeof(client_message) - 1) == -1)
        error_handling("read error");
    printf("Message from client : %s\n", client_message);

    //2. 파일 보내기

    //파일 열기
    fp = fopen("20180221_134217.mp4", "rb"); // 이진 읽기 모드
    if (fp == NULL)
        error_handling("file open error");

    //추후 debug를 위해 파일 사이즈 전송
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    write(clnt_sock, &filesize, sizeof(filesize));

    //파일 전송
    while (1)
    {
        read_cnt = fread((void*)buf, 1, BUFSIZE, fp);
        if (read_cnt < BUFSIZE) {
            write(clnt_sock, buf, read_cnt);
            break;
        }
        write(clnt_sock, buf, BUFSIZE);
    }

    //3. 데이터 모두 전송 후, half-close(출력 스트림만 끊음)
    if (shutdown(clnt_sock, SHUT_WR) == -1)
        error_handling("shutdown error");

    //4. client가 보낸 메시지 받기
    if (read(clnt_sock, client_message, sizeof(client_message) - 1) == -1)
        error_handling("read error");
    printf("Message from client : %s\n", client_message);

    //5. Good bye 메시지 보내기
    write(clnt_sock, server_message, sizeof(server_message));

    //파일 및 소켓 닫기
    fclose(fp);
    close(clnt_sock);
    close(serv_sock);
    return 0;
}

void error_handling(char* message)
{
    fputs(message, stderr);
    fputc('\n', stderr);
    exit(1);
}