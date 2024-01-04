#include <iostream>
#include <string>

using namespace std;

int main() {
	string s;
	cin>>s;
	
	int n_pos=0;
	int s_pos=0;
	int nArray[s.size()]={0,};
	string sArray;
	
	while(s_pos<s.size()){
		if (isdigit(s[s_pos])){
			nArray[n_pos]=nArray[n_pos]*10+stoi(s.substr(s_pos, 1));
			if (!isdigit(s[s_pos+1])){
				n_pos++;
			}
		}
		else{
			sArray.append(s.substr(s_pos, 1));
		}
		s_pos++;
	}
	
	int pos=0;
	int result=nArray[pos];
	pos++;
	int last_operator=0;
	for (int i=0;i<sArray.size();i++){
		//add
		if (sArray[i]=='a'&&i<sArray.size()-2){
			if (sArray[i+1]=='d'){
				if (sArray[i+2]=='d'){
					if (pos<n_pos){ // 숫자를 다 사용했지만 연산자가 남았다면 남은 연산자는 버린다.
						result+=nArray[pos];
						pos++;
					}
					last_operator=1; // add
				}
			}
		}
		//subtract
		if (sArray[i]=='s'&&i<sArray.size()-7){
			if (sArray[i+1]=='u'){
				if (sArray[i+2]=='b'){
					if (sArray[i+3]=='t'){
						if (sArray[i+4]=='r'){
							if (sArray[i+5]=='a'){
								if (sArray[i+6]=='c'){
									if (sArray[i+7]=='t'){
										if (pos<n_pos){
											result-=nArray[pos];
											pos++;
										}
										last_operator=2; // subtract
									}
								}
							}
						}
					}
				}
			}
		}
		//multiply
		if (sArray[i]=='m'&&i<sArray.size()-7){
			if (sArray[i+1]=='u'){
				if (sArray[i+2]=='l'){
					if (sArray[i+3]=='t'){
						if (sArray[i+4]=='i'){
							if (sArray[i+5]=='p'){
								if (sArray[i+6]=='l'){
									if (sArray[i+7]=='y'){
										if (pos<n_pos){
											result*=nArray[pos];
											pos++;
										}
										last_operator=3; // multiply
									}
								}
							}
						}
					}
				}
			}
		}
		//divide
		if (sArray[i]=='d'&&i<sArray.size()-5){
			if (sArray[i+1]=='i'){
				if (sArray[i+2]=='v'){
					if (sArray[i+3]=='i'){
						if (sArray[i+4]=='d'){
							if (sArray[i+5]=='e'){
								if (pos<n_pos){
									result/=nArray[pos];
									pos++;
								}
								last_operator=4; // divide
							}
						}
					}
				}
			}
		}
	}
	//모든 연산자를 한 번씩 사용하였지만 숫자가 남았다면 마지막 연산자를 반복 수행한다.
	while(pos<n_pos){
		if (last_operator==1){
			result+=nArray[pos];
		}
		else if (last_operator==2){
			result-=nArray[pos];
		}
		else if (last_operator==3){
			result*=nArray[pos];
		}
		else if (last_operator==4){
			result/=nArray[pos];
		}
		pos++;
	}
	
	cout<<result<<endl;
	
	return 0;
}