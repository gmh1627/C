#include<stdio.h>
#include<time.h>
int main(){
	int n=0;
	time_t t1,t2;
	char ch;
	time(&t1);//获取时间并存入变量
	while(ch=getchar()!='#')//输入并显示所输入的字符
		n++;
	time(&t2);
	printf("the char of input:%d\nthe velocity of naverage:%.2f/s\n",n,(n*1.0)/(t2-t1));
	return 0;
}
