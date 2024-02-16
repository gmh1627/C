#include<stdio.h>
#include<math.h>
#include<string.h>
int main(int argc, char *argv[]){
	int i;
	double ave,variance,*p,sum=0.0;
	p=(double*)calloc(sizeof(double),argc-1);
	for(i=0;i<argc-1;i++){
		p[i]=atof(argv[i+1]);
		sum+=p[i];
	}
	ave=sum/(argc-1);
	sum=0;
	for(i=0;i<argc-1;i++)
		sum+=pow(p[i]-ave,2.0);
	printf("%lf",variance=sum/(argc-1));	
	free(p);
	return 0;
}
