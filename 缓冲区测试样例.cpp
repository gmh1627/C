#include<stdio.h>
int main(){
	char str1[10],str2[10],str3[10];
	char a,b;
	int x,y,z;
	printf("������str1  a\n");
	scanf("%s%c",str1,&a);  
//	scanf("%s",str1);  //���������������һ���������滻��ʵ��str1 a������۲���ʲô��ͬ 
//	getchar();
//	scanf("%c",&a);
	printf("str1--->%s, a--->%c\n",str1,a);  //a ��ȡ�˻س��� 
	
	printf("������str2  ����x\n");
	scanf("%s%d",str2,&x);
	printf("str2--->%s, x--->%d \n",str2,x);  //��Ȼ���лس�����x�ܹ���ȷ��ȡ���� 
	
	printf("������str3  b\n");
	getchar();
	gets(str3);
	b=getchar();
	//scanf("%c",&b); 
	printf("str3--->%s, b--->%c\n",str3,b); //gets��ѻ������س�����
}

