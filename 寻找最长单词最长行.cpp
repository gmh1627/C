#include<stdio.h>
int main(){
	char st[200],*begin=st,*end=st,*p=st;
	int length=0;
	printf("������һ������\n");
	gets(st);
	for(;*p!='\0';p++){
		if(*p>= 'a' && *p <= 'z'||*p>= 'A' &&*p <= 'Z')
			length++;
		else
			length=0;
		if(length>end-begin){
			begin=p-length+1;
			end=p;
		}
	}
	printf("�����������ĵ����ǣ�\n");
	for(p=begin;p<=end;p++)
		printf("%c",*p);
	return 0;
}
/*#include<stdio.h>
#include<string.h>
int main() {
	char save[80] = { 0 },line[80];
	int max = 0, len��i = 0;
	while (strlen(gets(line)) != 0) {
		len = strlen(line);
		if (len > max) {
			max = len;	strcpy(save, line);
		}
	}
	printf("������ǣ�%s\n", save);
}
*/
