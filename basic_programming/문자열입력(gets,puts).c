#pragma warning (disable: 4996)
#include <stdio.h>

int main() {

	char str[40];

	//scanf("%s", str);
	// 문자열인 경우 & 안씀(str 자체가 주소이므로)
	// %c(문자 하나)가 오면 배열 요소가 와야하므로 값인 str[0]앞에 &붙여야함.
	gets(str); // 공백 포함

	// 'a'는 문자 a, "a"는 문자열 a(주소까지 저장).

	//printf("%s\n", str); 
	// str[0]부터 시작해서 null char만날때까지 출력
	puts(str);
	


	return 0;
}