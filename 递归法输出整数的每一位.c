#include<stdio.h>
void test(int n) {
	if (n > 9)
		test(n / 10);
	printf("%d ", n % 10);
}
int main() {
	int n ;
	printf("������һ������");
	scanf("%d", &n);
	if (n < 0) {
		printf("-");
		n = -n;
	}
	test(n);
	return 0;
}
