#include<stdio.h>
#include<windows.h>
BOOL Beep(DWORD dwFreq,DWORD dwDuration);
int main(){
	FILE *fp;
	unsigned int freq,duration;
	fp=fopen("music.txt","r");
	while(!feof(fp)){
		fscanf(fp,"%d %d",&freq,&duration);
		Beep(freq,duration);
	}
	fclose(fp);
	return 0;
}
