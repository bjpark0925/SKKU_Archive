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
    FILE* fp; // ���� ������(.mp4������ ����Ŵ)

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

    //���� ����
    serv_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (serv_sock == -1)
        error_handling("socket error");

    //serv_addr �ּ� ����
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

    //������ �ְ�ޱ�

    //1. client�� ���� �޽��� �ޱ�
    if (read(clnt_sock, client_message, sizeof(client_message) - 1) == -1)
        error_handling("read error");
    printf("Message from client : %s\n", client_message);

    //2. ���� ������

    //���� ����
    fp = fopen("20180221_134217.mp4", "rb"); // ���� �б� ���
    if (fp == NULL)
        error_handling("file open error");

    //���� debug�� ���� ���� ������ ����
    fseek(fp, 0, SEEK_END);
    filesize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    write(clnt_sock, &filesize, sizeof(filesize));

    //���� ����
    while (1)
    {
        read_cnt = fread((void*)buf, 1, BUFSIZE, fp);
        if (read_cnt < BUFSIZE) {
            write(clnt_sock, buf, read_cnt);
            break;
        }
        write(clnt_sock, buf, BUFSIZE);
    }

    //3. ������ ��� ���� ��, half-close(��� ��Ʈ���� ����)
    if (shutdown(clnt_sock, SHUT_WR) == -1)
        error_handling("shutdown error");

    //4. client�� ���� �޽��� �ޱ�
    if (read(clnt_sock, client_message, sizeof(client_message) - 1) == -1)
        error_handling("read error");
    printf("Message from client : %s\n", client_message);

    //5. Good bye �޽��� ������
    write(clnt_sock, server_message, sizeof(server_message));

    //���� �� ���� �ݱ�
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