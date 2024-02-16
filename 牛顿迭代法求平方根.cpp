# include<stdio.h>
# include<math.h> 
int main()
{
	int a;
	double x1,x2=1.0;
	scanf("%d",&a);
	do{
		x1=x2;
		x2=(x1+a/x1)/2;
	}while(fabs(x1-x2)>=0.00001);
	printf("%0.3lf",x2);
	return 0;
}

