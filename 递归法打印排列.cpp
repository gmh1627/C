#include<stdio.h>
#define N 4
int a[N];
void perm(int); /*求数组的全排列 */
void print();
void swap(int, int);
int main(){
	int i;
	for(i = 0; i < N; ++i)
		a[i] = i + 1;
	perm(0);
}

void perm(int offset){
	int i, temp;
	if(offset == N-1)// BaseCase
		print();
	else
		for(i = offset;i < N; ++i){
			swap(i, offset);//交换前缀
			perm(offset + 1);//递归
			swap(i, offset);//将前缀换回来，继续做前一次排列
		}
}

void print(){
	int i;
	for(i = 0; i < N; ++i)
	printf(" %d ",a[i]);
	printf("\n");
}

void swap(int i, int offset){
	int temp;
	temp = a[offset];
	a[offset] = a[i];
	a[i] = temp;
}
/*
#include<stdio.h>
#define N 4
#define M 2 // 取出M个元素进行排列，默认M<=N
void print(){
	int i,a[100];
	for(i = 0; i < M; ++i) // N->M，打印a里前M个排列元素
	printf(" %d ",a[i]);
	printf("\n");
}

void perm(int offset){
	int i;
	if(offset == M) // N->M，排列到M个数时递归到达BaseCase
		print();
	else
		for(i = offset;i < N; ++i){
			swap(i, offset);
			perm(offset + 1);
			swap(i, offset);
		}
}*/
