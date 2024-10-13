#include<stdio.h>
int main()
{
    int a,b,c;
    a=2,b=3,c=4;
    a+=a+b;
    printf("%d\n",a);
    a=2;
    a*=b%c;
    printf("%d\n",a);
    a=2;
    a/=c-a;
    printf("%d\n",a);
    a=2;
    a+=a-=a*=a;
    printf("%d\n",a);
    a=2;
    a=(a=++b,a+5,a/5);
    printf("%d\n",a);//结果为0，与笔算不符
    return 0;
}