#include <cstdio>
#include <string>
#include <iostream>

//iostream cin cout을 코딩시 사용하면 안됩니다!

//코드 입력
std::string cin(){
	char c[1000];
	scanf("%s", c);
	std::string s=c;
	
	return s;
}
namespace My_std{
	void cout(std::string s){
		for (int i=0;i<s.size();i++){
      char ch=s[i];
      putchar(ch);
    }
	}
}
/*
namespace My_std{
	void cout(std::string s){
		printf("%s", s.c_str());
	}
}
*/
int main() {
	std::string a = cin();
	My_std::cout(a+'\n');
	std::cin >> a;
	std::cout << a << std::endl;
  return 0;
}