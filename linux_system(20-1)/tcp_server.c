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

	//sockaddr_in은 소켓 주소의 틀을 형성해주는 구조체, IPv4용 구조체
	struct sockaddr_in serv_addr;
	struct sockaddr_in clnt_addr; // accept()에서 사용
	socklen_t clnt_addr_size;

	char client_message[30]; // client가 server에 보낸 메시지를 저장
	char server_message[] = "Hello Client"; // server가 client에 보내는 메시지

	if (argc != 2) { // 입력 시 port번호가 누락된 경우
		printf("Error : %s <port>\n", argv[0]);
		exit(1);
	}

	//소켓 생성
	//socket함수는 int형을 반환하는 socket(int domain, int type, int protocol)형태임
	serv_sock = socket(PF_INET, SOCK_STREAM, 0); // PF_INET은 IP를 사용하는 프로토콜 체계, SOCK_STREAM은 TCP방식을 의미, 0은 type에서 미리 정해진 프로토콜 방식을 따름 
	if (serv_sock == -1)
		error_handling("socket error");

	//serv_addr의 주소를 초기화한 후, IP주소와 포트 지정
	memset(&serv_addr, 0, sizeof(serv_addr));
	serv_addr.sin_family = AF_INET; // 타입: IPv4(IP를 사용하는 주소체계)
	serv_addr.sin_addr.s_addr = htonl(INADDR_ANY); // htonl(long형 데이터의 바이트 오더를 호스트(리틀엔디안)방식에서 네트워크(빅엔디안)방식으로 변환)로 IP주소 저장
	serv_addr.sin_port = htons(atoi(argv[1])); // port

	//IP주소와 포트를 소켓에 결합
	if (bind(serv_sock, (struct sockaddr*) & serv_addr, sizeof(serv_addr)) == -1)
		error_handling("bind error");

	//연결을 기다림(대기열은 5개)
	if (listen(serv_sock, 5) == -1)
		error_handling("listen error");

	//연결 요청을 수락하는 단계
	clnt_addr_size = sizeof(clnt_addr);
	clnt_sock = accept(serv_sock, (struct sockaddr*) & clnt_addr, &clnt_addr_size);
	if (clnt_sock == -1)
		error_handling("accept error");

	//데이터 주고받기

	//1. client가 보낸 메시지 받기
	if (read(clnt_sock, client_message, sizeof(client_message) - 1) == -1)
		error_handling("read error");
	printf("Message from client : %s\n", client_message);

	//2. server가 "Hello Client"메시지 보내기
	write(clnt_sock, server_message, sizeof(server_message));

	//소켓 닫기
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