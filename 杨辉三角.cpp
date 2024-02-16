#include <stdio.h>
int main()
{
	int a[6][6],i,j;
	for(i=0;i<6;i++)
	{
		a[i][0]=1;
		a[i][i]=1;
	}
	for(i=2;i<=5;i++)
	{
		for(j=1;j<=i-1;j++)
		{
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
	}
	for(i=0;i<=5;i++)
		{
			for(j=0;j<=i;j++)
			{
			printf("%3d",a[i][j]);
			}	
			printf("\n"); 
		}
}
	
