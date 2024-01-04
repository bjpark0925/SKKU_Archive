#include <iostream>
using namespace std;
int main() {
	int a,b;
	cin>>a;
	cin>>b;
	
	// 3차원 배열 동적 할당
    int ***matrix = new int**[a];
    for (int i = 0; i < a; i++) {
        matrix[i] = new int*[a];
        for (int j = 0; j < a; j++) {
            matrix[i][j] = new int[a];
        }
    }

    // 3차원 배열 초기화
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
            for (int k = 0; k < a; k++) {
                matrix[i][j][k] = b;
            }
        }
    }

    // 3차원 배열 출력
    for (int i = 0; i < a; i++) {
        for (int j = 0; j < a; j++) {
						if (j==0){
								cout<<"[";
						}
            for (int k = 0; k < a; k++) {
								if (k==0){
									cout<<"["<<matrix[i][j][k];
									if (k==a-1){
										cout<<"]";
									}
									else{
										cout<<", ";
									}
								}
								else if (k==a-1){
									cout<<matrix[i][j][k]<<"]";
								}
								else{
									cout<<matrix[i][j][k]<<", ";
								}
            }
						if (j==a-1){
							cout<<"]"<<endl;
						}
						else{
							cout<<", ";
						}
        }
    }

    // 3차원 배열 동적 해제
    for (int i = 0; i < a; ++i) {
        for (int j = 0; j < a; ++j) {
            delete[] matrix[i][j];
        }
        delete[] matrix[i];
    }
    delete[] matrix;
	
	return 0;
}