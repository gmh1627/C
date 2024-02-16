#include<stdio.h>
#include<stdlib.h>//声明rand()函数
#include<time.h>//声明time()函数
int main(){
	int i,a[100],m,n;
	printf("请输入随机数的上界和下界");
	scanf("%d%d",&m,&n);
	srand(time(NULL));//生成随机数种子
	for(i=0;i<100;i++)
		printf("%d\t",rand() % ( m- n + 1) + n);
	return 0;
}

/*#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int i,j,a[100],b[1000];
	float Percentage1[20],Percentage2[20],sum1[20],sum2[20];
	srand(time(NULL));//初始化随机数发生器
	for(i=0;i<100;i++){
		a[i]= rand() % 20;
		for(j=0;j<20;j++){
			if(a[i]==j)
				sum1[j]=sum1[j]+1.0;
		}
	}
		for(j=0;j<20;j++){
			Percentage1[j]=sum1[j]/100.0;
			printf("%d所占的比例是%.2f\n",j,Percentage1[j]);
		}
	printf("\n");
	for(i=0;i<1000;i++){
		b[i]= rand() % 20;
		for(j=0;j<20;j++){
			if(b[i]==j)
				sum2[j]=sum2[j]+1.0;
		}
	}
		for(j=0;j<20;j++){
		Percentage2[j]=sum2[j]/1000.0;
		printf("%d所占的比例是%.3f\n",j,Percentage2[j]);
	}
	return 0;
}
	
*/
