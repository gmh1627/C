#include<stdio.h>
void h(int n,char source,char destination,char temp){
	if(n==1)
		printf("%c->%c\n",source,destination);//��source�����ϲ�������Ƶ�destination�����ϲ�
	else{
		h(n-1,source,temp,destination);//��������Ҫ��n�����Ӵ�a�Ƶ�b���������Ȱ������n-1�������Ƶ�ʣ�µ�����c
		h(1,source,destination,temp);//�ٰ��������Ǹ����Ӵ�a�Ƶ�b
		h(n-1,temp,destination,source);//����n-1�����Ӵ�c�Ƶ�a,������תΪn-1�����ӵ���������ϵݹ�
	}
}
int main(){
	int n;
	scanf("%d",&n);
	h(n,'a','b','c');
}
