#include<stdio.h>
#include<stdlib.h>
#define n 7
int main()
{
	int value[n] = { 1,2,5,10,20,50,100 };//纸币面额
	int a[n] = { 5,5,0,0,2,1,3 };//分别的数量
	int m, i, num = 0, c = 0;
	scanf("%d", &m);
	for (i = n - 1; i >= 0; i--)
	{
		if (m / value[i] <= a[i])
			c = m / value[i];
		else
			c = a[i];
		m = m - c * value[i];
		num += c;
	}
	if (m > 0)
		num = -1;
	if (num != -1)
		printf("%d", num);
	else printf("wujie");
	system("pause");
}