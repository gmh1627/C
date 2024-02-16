#include<stdio.h>
int additiveSequence(int n, int t0, int t1);
int fib(int n);
int main(){
	int n,i;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
		printf("斐波那契数列第%d个数是%d\n",i,fib(i));
	return 0;
}
int fib(int n){
	return additiveSequence(n, 0, 1);
}

int additiveSequence(int n, int t0, int t1){
	if (n==0) 
		return t0;
	if (n==1) 
		return t1;
	return additiveSequence(n-1, t1, t0+t1);
}

