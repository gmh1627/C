#include<stdio.h>
void h(int n,char source,char destination,char temp){
	if(n==1)
		printf("%c->%c\n",source,destination);//把source处最上层的盘子移到destination处最上层
	else{
		h(n-1,source,temp,destination);//假设我们要把n个盘子从a移到b，则我们先把上面的n-1个盘子移到剩下的柱子c
		h(1,source,destination,temp);//再把最下面那个盘子从a移到b
		h(n-1,temp,destination,source);//最后把n-1个盘子从c移到a,把问题转为n-1个盘子的情况，不断递归
	}
}
int main(){
	int n;
	scanf("%d",&n);
	h(n,'a','b','c');
}
