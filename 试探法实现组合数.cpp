#include <stdio.h>
#define MAX 100
int a[MAX];
void comb(int n, int r){
	int i=0, j;
	a[i]= 1;
	do{
		if(a[i]-i<=n-r+1){//��������ǰ��̽ 
			if(i==r-1){//�ҵ�һ�����
				for(j=0; j<r; j++)  //���һ����� 
					printf("%4d", a[j]);
				printf("\n");
				a[i]++;
				continue;
			} 
			i++;  //��ǰ��̽ 
			a[i]= a[i-1]+1;
		}
		else{//��ʼ����  
			if(i==0)  //����ȫ����
				return;  //���нⶼ�ҵ��˲ŷ��أ��������� 
			a[--i]++; 
		}
	}while(1);
} 

int main(){
	int x, y;
	printf("��涨��ֹ������1��ʼ���ͼ�������ϣ�");
	scanf("%d%d",&x,&y);
	printf("��Ȼ��1~%d��%d��������������У�\n", x, y);
	comb(x, y);
}
