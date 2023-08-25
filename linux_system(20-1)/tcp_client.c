#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <sys/socket.h>

void error_handling(char* message);

int main(int argc, char* argv[])
{
	int clnt_sock;

	struct sockaddr_in serv_addr;
	char client_message[30] = "Hello Server"; // client�� server�� ������ �޽���
	char server_message[30]; // server�� client�� ���� �޽����� ����

	if (argc != 3) { // �Է� �� IP�ּҳ� port��ȣ�� ������ ���
		printf("Error : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	//TCP���, IPv4 �������� ���� ���� ����
	clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (clnt_sock == -1)
		error_handling("socket error");

	//������ �ּ�ü��, IP, port ����
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	//client���Ͽ� server�� �����ϴ� connect����
	if (connect(clnt_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect error!");

	//������ �ְ�ޱ�
	
	//1. client�� "Hello Server"�޽��� ������
	write(clnt_sock, client_message, sizeof(client_message));

	//2. server�� ���� �޽��� �ޱ�
	if (read(clnt_sock, server_message, sizeof(server_message) - 1) == -1)
		error_handling("read error!");
	printf("Message from server: %s \n", server_message);


	close(clnt_sock);
	return 0;
}

void error_handling(char* message)
{
	fputs(message, stderr);
	fputc('\n', stderr);
	exit(1);
}
