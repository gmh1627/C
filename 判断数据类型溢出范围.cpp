#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	short a = 1;
	long int b = 1;
	unsigned c = 1;
	long long d = 2;
	while (a > 0) a++;
	while (b > 0) b++;
	while (c > 0)c++;
	while (d > 0) d = pow(d, 2);
	printf("%d%d\n", a - 2, a);
	printf(" % ld % ld\n", b - 1, b);
	printf("%u%u\n", c - 1, c);
	printf("%lld%lld", d - 1, d);
	return 0;
}
	
