#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
 
typedef struct student{
	long int stunum;
	char name[20];
	float examscore;
	float labscore;
	float totalmark;
	student *next;
}STU;

STU *creat(){
	STU *p,*head,*first;
	FILE *fp;
	head=(struct student *)malloc(sizeof(struct student));
	first=NULL;
	fp=fopen("students.txt","r");
	while(!feof(fp)){
		p=(struct student *)malloc(sizeof(struct student));
		fscanf(fp,"%ld %s %f %f",&p->stunum,p->name,&p->examscore,&p->labscore);
		p->totalmark=0.6*p->examscore+0.4*p->labscore;
		p->next=first;
		first=p;
	}
	fclose(fp);
	head->next=first;
	return head;
};

void PrintList(STU *head){
	STU *p=head->next;
	while(p){
		printf("%ld\t%s\t%.2f\t%.2f\t%.2f\n",p->stunum,p->name,p->examscore,p->labscore,p->totalmark);
		p=p->next;
	}
}

STU* sort(STU*p){
	STU *p1, *p2, *p3, *end, *temp,*head=p;
	end=NULL;
	while(head->next!=end){
		for(p1=head,p2=p1->next,p3=p2->next;p3!=end;p1=p1->next,p2=p2->next,p3=p3->next){
			if(p2->totalmark<p3->totalmark){
				p1->next=p2->next;
				p2->next=p3->next;
				p3->next=p2;
				temp=p2;
				p2=p3;
				p3=temp;
			}
		}
		end=p2;
	}
	return head;
}

void Grade_Print(STU *head,int min,int max){
	float sum=0.0,ave=0.0;
	int num=0;
	STU *q=head->next;//防止主函数里的head指向不同地方
	while(q){
		if(q->totalmark>min&&q->totalmark<=max){
			sum+=q->totalmark;
			printf("%ld\t%s\t%.2f\t%.2f\t%.2f\n",q->stunum,q->name,q->examscore,q->labscore,q->totalmark);
			num++;
			q=q->next;
		}
		else 
			q=q->next;	
	}
	if (num>0){
		ave=sum/num;
		printf("在(%d,%d]分数段的学生有%d人,平均分是%.2f\n",min,max,num,ave);
	}
	else
		printf("在(%d,%d]分数段没有学生\n",min,max);
}
	
int main(){
	STU *head;
	head=creat();
	PrintList(head);
	printf("\n");
	head=sort(head);
	PrintList(head);
	printf("\n");
	Grade_Print(head,90,100);
	Grade_Print(head,80,90);
	Grade_Print(head,70,80);
	Grade_Print(head,60,70);
	Grade_Print(head,0,60);
	return 0;
}	
