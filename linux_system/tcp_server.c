#include <stdio.h>
#include <stdlib.h> // atoi
#include <string.h> // memset
#include <unistd.h> // sockaddr_in, read(), write()
#include <arpa/inet.h> // htnol, htons, INADDR_ANY
#include <sys/socket.h>

void error_handling(char* message);

int main(int argc, char* argv[])
{
	int serv_sock;
	int clnt_sock;

	//sockaddr_in�� ���� �ּ��� Ʋ�� �������ִ� ����ü, IPv4�� ����ü
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr; // accept()���� ���
	socklen_t clnt_addr_size;

	char client_message[30]; // client�� server�� ���� �޽����� ����
	char server_message[] = "Hello Client"; // server�� client�� ������ �޽���

	if (argc != 2) { // �Է� �� port��ȣ�� ������ ���
		printf("Error : %s <port>\n", argv[0]);
		exit(1);
	}

	//���� ����
	//socket�Լ��� int���� ��ȯ�ϴ� socket(int domain, int type, int protocol)������
	serv_sock = socket(PF_INET, SOCK_STREAM, 0); // PF_INET�� IP�� ����ϴ� �������� ü��, SOCK_STREAM�� TCP����� �ǹ�, 0�� type���� �̸� ������ �������� ����� ���� 
	if (serv_sock == -1)
		error_handling("socket error");

	//serv_addr�� �ּҸ� �ʱ�ȭ�� ��, IP�ּҿ� ��Ʈ ����
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; // Ÿ��: IPv4(IP�� ����ϴ� �ּ�ü��)
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // htonl(long�� �������� ����Ʈ ������ ȣ��Ʈ(��Ʋ�����)��Ŀ��� ��Ʈ��ũ(�򿣵��)������� ��ȯ)�� IP�ּ� ����
	serv_addr.sin_port = htons(atoi(argv[1])); // port

	//IP�ּҿ� ��Ʈ�� ���Ͽ� ����
	if (bind(serv_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind error");

	//������ ��ٸ�(��⿭�� 5��)
	if (listen(serv_sock, 5) == -1)
		error_handling("listen error");

	//���� ��û�� �����ϴ� �ܰ�
	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*) & clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1)
		error_handling("accept error");

	//������ �ְ�ޱ�

	//1. client�� ���� �޽��� �ޱ�
	if (read(clnt_sock, client_message, sizeof(client_message) - 1) == -1)
		error_handling("read error");
	printf("Message from client : %s\n", client_message);

	//2. server�� "Hello Client"�޽��� ������
	write(clnt_sock, server_message, sizeof(server_message));

	//���� �ݱ�
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