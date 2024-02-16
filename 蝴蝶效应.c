#include<stdio.h>
#include<math.h>
#define n 1000
#define u0 3.56994558
int main()
{
	int i,j,k,c1=0,c2=0,c3=0,c4=0,c5=0,c6=0,c7=0,c8=0,c9=0,c10=0;
	double u;
	for(i=0;i*pow(10,-1)+u0<=4;i++)
	{
		u=u0+i*pow(10,-1);
		printf("u is %.8f\n",u);
		for(k=1;k<=5;k++)
		{
			double x[n+1];
			x[0]=0.1*k;
			printf("x0 is %.1f\n",x[0]);
			printf("0-0.1 0.1-0.2 0.2-0.3 0.3-0.4 0.5-0.6 0.6-0.7 0.7-0.8 0.8-0.9 0.9-1.0\n");
			for(j=1;j<n;j++)
			{
				x[j]=u*x[j-1]*(1-x[j-1]);
				if(x[j]>0&&x[j]<=0.1) c1++;
				else if(x[j]>0.1&&x[j]<=0.2) c2++;
				else if(x[j]>0.2&&x[j]<=0.3) c3++;
				else if(x[j]>0.3&&x[j]<=0.4) c4++;
				else if(x[j]>0.4&&x[j]<=0.5) c5++;
				else if(x[j]>0.5&&x[j]<=0.6) c6++;
				else if(x[j]>0.6&&x[j]<=0.7) c7++;
				else if(x[j]>0.7&&x[j]<=0.8) c8++;
				else if(x[j]>0.8&&x[j]<=0.9) c9++;
				else if(x[j]>0.9&&x[j]<=1.0) c10++;
			}
			printf("%d %d %d %d %d %d %d %d %d %d",c1,c2,c3,c4,c5,c6,c7,c8,c9,c10);
			printf("\n");
		}
		printf("\n\n");
	}
}

