#include<stdio.h>
#include<stdlib.h>
/*struct student {
	char name[16];
	float english, math, physics, total;
	};
int main(){
	int i;*/
	//FILE *fp;
	/*struct student stu[3] = {
								{"zhangsan", 90, 92, 96, 0},
								{"Liming" ,85, 88, 95, 0},
								{"Gaofei" , 95, 86, 92, 9}
							};
	for (i=0; i<3; i++)
		stu[i].total=stu[i].english+stu[i].math+stu[i].physics;
	fp = fopen("student.dat","wb");
	for(i=0;i<3;i++)
		fwrite(stu+i, sizeof(struct student), 1, fp);
	fclose(fp);
	fp = fopen("student.dat","rb");
	for(i=0; i<3; i++)
		fread(stu+i, sizeof(struct student), 1, fp);
	fclose(fp);
	for (i=0; i<3; i++)
		printf("%-16s%6.1f%6.1f%6.1f%7.1f\n",stu[i].name,stu[i].english, stu[i].math,stu[i].physics, stu[i].total);
	*/
	
	/*FILE *fp1,*fp2;
	int c;
	fp1=fopen("F:\\Desktop\\程序\\输出学生成绩链表\\students.txt","r");
	fp2=fopen("score.txt","w");
	while((c=fgetc(fp1))!=EOF)
		fputc(c,fp2);
	if(ferror(fp1))
		puts("Error");
	else if(feof(fp1))
	puts("End");
	fclose(fp1);
	fclose(fp2);*/
	
	/*FILE *fp;
	char a[20];
	fp=fopen("name.txt","w+");
	fputs("Alan Turning\n",fp);
	fputs("John von Neumann\n",fp);
	rewind(fp);
	while(fgets(a,sizeof(a),fp)!=NULL)
		printf("%s",a);
	fclose(fp);*/
int main()
{
	FILE *fp;
	char st[10]="ab";
	fp = fopen("student1.txt","r+");
	//scanf("%s",st);
	//fread(st,sizeof(st),1,fp);
	//printf("%s",st);
	//rewind(fp);
	fwrite(st,sizeof(st),1,fp);
	rewind(fp);
	fread(st,sizeof(st),1,fp);
	printf("%s",st);
	fclose(fp);
	return 0;
}
