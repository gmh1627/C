#include<stdio.h>
int main(){
	char str1[10],str2[10],str3[10];
	char a,b;
	int x,y,z;
	printf("请输入str1  a\n");
	scanf("%s%c",str1,&a);  
//	scanf("%s",str1);  //将这三条语句与上一条语句进行替换，实现str1 a的输入观察有什么不同 
//	getchar();
//	scanf("%c",&a);
	printf("str1--->%s, a--->%c\n",str1,a);  //a 读取了回车符 
	
	printf("请输入str2  数字x\n");
	scanf("%s%d",str2,&x);
	printf("str2--->%s, x--->%d \n",str2,x);  //虽然仍有回车，但x能够正确读取数字 
	
	printf("请输入str3  b\n");
	getchar();
	gets(str3);
	b=getchar();
	//scanf("%c",&b); 
	printf("str3--->%s, b--->%c\n",str3,b); //gets会把缓冲区回车丢掉
}

