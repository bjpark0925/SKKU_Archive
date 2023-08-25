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
    char client_message[30] = "Hello Server"; // client�� server�� ������ �޽���
    char debug_message1[30] = "Different Size";
    char debug_message2[30] = "Same Size";
    char server_message[30]; // server�� client�� ���� �޽����� ����

    int read_cnt;
    int filesize = 0;
    int recvsize;
    

    if (argc != 3) {
        printf("Error : %s <IP> <port>\n", argv[0]);
        exit(1);
    }

    //���� ����
    clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
    if (clnt_sock == -1)
        error_handling("socket() error");

    //serv_addr �ּ� ����
    memset(&serv_addr, 0, sizeof(serv_addr));
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
    serv_addr.sin_port = htons(atoi(argv[2]));

    //connect
    if (connect(clnt_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
        error_handling("connect() error!");

    //������ �ְ�ޱ�

    //1. client�� "Hello Server"�޽��� ������
    write(clnt_sock, client_message, sizeof(client_message));

    //2. ���� �ޱ�

    //���� debug�� ���� ���� ���� ������ �ޱ�
    read(clnt_sock, &filesize, sizeof(filesize));

    //���� ����(������ �������� �����Ƿ� �� ���� ���� ������)
    fp = fopen("receive.mp4", "wb"); // ���� ���� ���
    if (fp == NULL)
        error_handling("file open error");

    //���� ����
    while ((read_cnt = read(clnt_sock, buf, BUFSIZE)) != 0)
    {
        fwrite((void*)buf, 1, read_cnt, fp);
    }

    //3. ���� ���ϰ� ���� ���� ������ ��
    fseek(fp, 0, SEEK_END);
    recvsize = ftell(fp);
    fseek(fp, 0, SEEK_SET);

    //4. ������ �� ��, �˸��� �޽��� ������
    if (filesize != recvsize)
        write(clnt_sock, debug_message1, sizeof(debug_message1));
    else
        write(clnt_sock, debug_message2, sizeof(debug_message2));

    //4. Good bye �޽��� �ޱ�
    if (read(clnt_sock, server_message, sizeof(server_message) - 1) == -1)
        error_handling("read error!");
    printf("Message from server: %s \n", server_message);

    //���� �� ���� �ݱ�
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