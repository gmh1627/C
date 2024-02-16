#include<stdio.h>
#include<string.h>
#include<math.h>
/*int fun(int a){
		int b=1;
		static int c=1;
		a++;
		b++;
		c++;
		return(a+b+c);
	}*/
void swap(int *x,int* y){
	int *t;
	t=x,x=y,y=t;
}
int main()
{
	//int i=1,j=2,*x=&i,*y=&j;
	//swap(x,y);
	//printf("%d %d",*x,*y);
	//char s1[20]="hello",s2[10]="world";
		//for (i = 0; (s1[i-1] = s2[i++]) != '\0';);
	//printf("%s",s1);
	//float c=1.,d=.2;
	//printf("%f %f",c,d);
	
	/*char a[20]="kill";
	char s[20]="case",*p;
	int i,j;
	for(p=s;*p;p++){
		j=0;
		while(*p>=a[j]&&a[j]!='\0'){
			j++;	
		}
		for(i=strlen(a);i>=j;i--){
			a[i+1]=a[i];
		}
		a[j]=*p;
	}
	printf("%s",a);
	int b=0;
		printf("%d\n",(b=5*4,b+5,b*4));*/
/*	int p=12;
	printf("%d",(p+=p-=p*=p));
	int a[5]={1,2},k=0,j=0;
	j+++1;
	printf("%d\n",j);
	//++k+1;
	printf("%d\n",++k+1);
	for(int i=0;i<5;i++)
	printf("%d",a[i]);
	char s[6]="china";
	printf("%c",s[0]);*/
	//char a='0009';
	//char st[]="m\x43\18";
	//printf("%d",sizeof(st));
	/*float a=6.732;
	printf("%g",a);
	void Blind(double *a, int n) {
	    int i; //??????????????????????????
	    for(i=0;i<n-1;i++)	 printf ("a[%d]=%f ",i,a[i]);
	}  
	int main() { //???????
		double a=3.2;
		Blind(&a, 6); *///?????????????
//	int i;
//	++i=3;
//float y,z;
//	float	x=y=z=3.14; 
//	double  x=6e2;
/*int i;
for(i=0;i<=3;i++){
	//TODO
};
	printf("%d",i);*/
	//int x;
	//printf("2.%d,",(printf("1:%d,",scanf("%d",&x))));
	//float x=3/2,y;
	//printf("%f",(x=3/2,y=x+5.0/2));
	//printf("%f",x);
	//unsigned char a=127,b;
	//b=a++;
	//printf("%d %d",a,b)
	//int x=-.28;
	//printf("%f",-.28);
	//int i=1;
	//for(;i<=3;i++)
	//	printf("%d",fun(i));
	//int m=10,n=10;
	//printf("%d",(m+n)++);//????????
	//int n=3,a[n]={1};
	//for(int i=0;i<3;i++)
	//	printf("%d",a[i]);
	
//	char s='\0';
//	printf("%d %d",s,EOF);
	//int *x=NULL;
	//printf("%p",*x);
	//int x=-5,y=0,z=4;
	//printf("%d %d\n",sizeof(++x),x);
	//printf("%d\n",y=(x=3,sizeof(++x),x));//x+=x*=x+1));
	//printf("%d",y=(z+=z*=z+1));
	//int a[3]={1,2,3};
	//printf("%d",a[-1]);
/*	int a[4][4] ={{1,2,3,4}};
	int(*p)[4],*q,*r,i,j;
	for(p=a+1;p<a+4;p++){
		r=*a;
		q =*p+(p-a);
	do{
		*q = *(r++);
		q=*p+((q-*p)+1)%4;
	} while (q!=*p+(p-a));
	}
	for (i =0; i < 4; i++){
		for (j = 0; j<4; j++)
			printf("%2d", a[i][j]);
		printf("\n");
	}*/
	//float a=3.0,b=2.0;
//	printf("%d",sizeof (a*b));
	//int *p=&1;
//	printf("%d %d",sizeof('a'),sizeof('\n'));	
//	long double a=1.0;
//	printf("%Lf",a);
	//printf("%f",pow(3,1.5));
//	printf("%d",printf("%s\n","4"));
	//char st[5]="USTC";
	//st[1]='a';
	//puts(st);
	//int x,*p,a=20;
	//p=&x;
	//printf("%#x %#p %#o %#X %#p",&x,p,p,a,a);
	//printf("%d",'abc');
	//char *ps="0123456789",st[11]="1234567890";
	//printf("%d %d %d %d %d",sizeof(ps),sizeof(*ps),sizeof(st),sizeof(*st),sizeof('ab'));
/*	char st[100]="hello\nworld";
	printf("%s",st);
	printf("%d",-15%4);
	char s='ab';
	printf("%d",sizeof s);
	char st[20];
	st=="abc";//注意这是判断两个字符串的地址是否相同，比较字符串要用strcmp
	char a,b;
	a=getchar();
	printf("%c",a);
	float a=2.0;
	printf("%f",pow(a,3.0));
	for(int i=0;i<3;i++)
	{
		i++;
		printf("%d\n",i);
	}*/
	//printf("()");
	unsigned int a=100,b=200;
	printf("%u",b-a);
	
}
	
