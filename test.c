#include <stdio.h>
#include <stdlib.h>
#define a 10
int main() {
    printf("%d\n", a);
    /*宏定义变量不能改*/
    //a = 20;
    //printf("%d\n", a);
    int i = 1;
    printf("%d\n", i++);
    printf("%d\n", i);
    printf("%d\n", ++i);
    //3a 3*a
    //注释里套注释
    //通常不对两个浮点数直接比较大小
    //'a'和a
    //I say:"Goodbye!"  转义字符
    //字符串长度strlen和sizeof的区别
    //字符串拼接strcat和strncat的区别
    //5 / 2 = 2 ；1 / 2 = 0
    //(float)5 / 2 = 2.5 ；(float)(1 / 2) = 0.5
    return 0;
}