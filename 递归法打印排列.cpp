#include<stdio.h>
#define N 4
int a[N];
void perm(int); /*�������ȫ���� */
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
			swap(i, offset);//����ǰ׺
			perm(offset + 1);//�ݹ�
			swap(i, offset);//��ǰ׺��������������ǰһ������
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
#define M 2 // ȡ��M��Ԫ�ؽ������У�Ĭ��M<=N
void print(){
	int i,a[100];
	for(i = 0; i < M; ++i) // N->M����ӡa��ǰM������Ԫ��
	printf(" %d ",a[i]);
	printf("\n");
}

void perm(int offset){
	int i;
	if(offset == M) // N->M�����е�M����ʱ�ݹ鵽��BaseCase
		print();
	else
		for(i = offset;i < N; ++i){
			swap(i, offset);
			perm(offset + 1);
			swap(i, offset);
		}
}*/
