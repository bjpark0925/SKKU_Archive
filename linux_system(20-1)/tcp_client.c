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
	char client_message[30] = "Hello Server"; // client가 server에 보내는 메시지
	char server_message[30]; // server가 client에 보낸 메시지를 저장

	if (argc != 3) { // 입력 시 IP주소나 port번호가 누락된 경우
		printf("Error : %s <IP> <port>\n", argv[0]);
		exit(1);
	}

	//TCP통신, IPv4 도메인을 위한 소켓 생성
	clnt_sock = socket(PF_INET, SOCK_STREAM, 0);
	if (clnt_sock == -1)
		error_handling("socket error");

	//서버의 주소체계, IP, port 저장
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_addr.s_addr = inet_addr(argv[1]);
	serv_addr.sin_port = htons(atoi(argv[2]));

	//client소켓에 server를 연결하는 connect과정
	if (connect(clnt_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
		error_handling("connect error!");

	//데이터 주고받기
	
	//1. client가 "Hello Server"메시지 보내기
	write(clnt_sock, client_message, sizeof(client_message));

	//2. server가 보낸 메시지 받기
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
