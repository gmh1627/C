#include<stdio.h>
int main()
{
    int a,b ;
    double x,y;
    a=56,b=10,x=3.5,y=1/2;
    printf("%f\n",x+y+a%b);
    a=3;
    printf("%d\n",a++*1/3);
    y=4.6;
    printf("%f\n",x+a%3*(int)(x+y)%2/4);
    a=2,b=3;
    printf("%f\n",(float)(a+b)/2+(int)x%(int)y);//与笔算结果均相符
    return 0;
}