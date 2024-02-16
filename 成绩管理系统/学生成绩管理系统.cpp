#include<stdio.h>
#include<math.h>
struct student
{
	char id[10];
	char name[10];
	char sex;
	float gpa1;
	float gpa2;
	float ave;
	float w_ave;
};
int main()
{
	FILE *fp;
	struct student st[3];
	struct student temp;
	float ave1=0.0, ave2=0.0;
	int i, j,k;
	while(1){
		printf("学生成绩录入系统\n----------\n1.录入成绩\n2.打印所有学生成绩\n3.打印所有不及格成绩\n\
4.从文件导入学生成绩\n5.打印所有学生成绩到文件\n6.按加权平均成绩从高到低排序\n0.退出\n==========\n请选择：");
		scanf("%d", &k);
		switch (k){
		case 1:
			printf("请输入学号、姓名、性别、数学分析成绩、线性代数成绩：\n"); 
			for (i = 0; i < 3; i++)
				scanf("%s %s %c %f %f", st[i].id, st[i].name, &st[i].sex, &st[i].gpa1, &st[i].gpa2);
			break;
		case 2:
			for (i = 0; i < 3; i++)
				printf( "%s\t%s\t%c\t%.2f\t%.2f\n", st[i].id, st[i].name, st[i].sex, st[i].gpa1, st[i].gpa2);
			break;
		case 3:
				for( i=0;i<3;i++){
					if(st[i].gpa1<2.0)
						printf("%s的数学分析成绩不及格,为%.1f分\n",st[i].name,st[i].gpa1);	
					if(st[i].gpa2<2.0)
						printf("%s的线性代数成绩不及格,为%.1f分\n",st[i].name,st[i].gpa2);	
				}
				break;
		case 4:
			fp = fopen("F:\\Desktop\\程序\\成绩管理系统\\student1.txt", "r");
			for (i = 0; i < 3; i++){
					fscanf(fp, "%s%s %c%f%f", st[i].id, st[i].name, &st[i].sex, &st[i].gpa1, &st[i].gpa2);//%s %c要分开，防止把空格读入%c
					printf("%s %s %c %.1f %.1f\n\n", st[i].id, st[i].name, st[i].sex,st[i].gpa1, st[i].gpa2);
				}
			fclose(fp);
			break;
		case 5:
			fp = fopen("student grade.txt", "w"); 
			for (i = 0; i < 3; i++)
				fprintf(fp, "%s %s %c %.1f %.1f\n", st[i].id, st[i].name, st[i].sex,st[i].gpa1, st[i].gpa2);
			fclose(fp);
			break;
		case 6:
			for (i = 0; i < 3; i++){
					st[i].ave=(st[i].gpa1+st[i].gpa2)/2.0;
					st[i].w_ave=(0.6*st[i].gpa1+0.4*st[i].gpa2);
					ave1+=st[i].gpa1/3;
					ave2+=st[i].gpa2/3;
				}
			for (i = 0; i < 2; i++){	
					for (j = i+1; j < 3; j++){
						if(st[i].w_ave<st[j].w_ave){
							temp=st[i];
							st[i]=st[j];
							st[j]=temp;
						}
					}
				}
			for (i = 0; i < 3; i++)
				printf( "%s %s %c 数学分析成绩是%.1f 线性代数成绩是%.1f 平均分是%.2f 加权平均分是%.2f\n", st[i].id, st[i].name, st[i].sex, st[i].gpa1, st[i].gpa2,st[i].ave,st[i].w_ave);
		case 0:goto loop;
		}
	}
	loop:return 0;	
}
