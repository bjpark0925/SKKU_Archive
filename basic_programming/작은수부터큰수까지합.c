#include<stdio.h>
int main() {

	int n, m, sum=0;
	int i;

	scanf_s("%d %d", &n, &m);

	if (n == m) printf("Equal");

	else if (n < m){
		for (i = n; i <= m; i++){
			sum += i;
			printf("%d", i);
			if (i < m) {
				printf("+");
			}
			else{
				printf("=");
			}
		}
	}
	else {
		for (i = m; i <= n; i++) {
			sum += i;
			printf("%d", i);
			if (i < n) {
				printf("+");
			}
			else {
				printf("=");
			}
		}
	}
	printf("%d", sum);
	
	return 0;
}