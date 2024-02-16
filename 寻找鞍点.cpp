#include<stdio.h>
int main(){
	int i,j,k,m,n,t,p;
	long long int a[100][100],max;
	printf("请依次输入行数和列数\n");
	scanf("%d%d",&n,&m);
	printf("请依次输入每行每列的数字\n");
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			scanf("%lld",&a[i][j]);
	for(i=0;i<n;i++){
		max=a[i][0];
		for(j=0;j<m;j++){
			if(a[i][j]>max){
				max=a[i][j];
				t=j;
			}
		}
		p=0;
		for(k=0;k<n;k++){
			if(max>a[k][t])
				break;
			else
				p++;
		}
		if (p==n){
			printf("%d %d\n",i+1,t+1);
			return 0;	
		}
	}
	printf("-1");//找不到鞍点输出-1
	return 0;
}
