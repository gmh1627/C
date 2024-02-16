#include<stdio.h>
#include<stdlib.h>
#define N 200
struct book *input_list(struct book*,int);
struct book *sort_list(struct book*,int);
int query_list(struct book*,int,int);
int insert_list(struct book*,int,struct book);
void print_list(struct book *,int);
struct book{
	int no;
	char name[100];
	float price;
	int num;
};
int main(){
	struct book list[N], new_book;
	int i, j, book_no, index,total_book;
	total_book=10;
	input_list(list,total_book);//����ͼ����Ϣ
	sort_list(list,total_book);//����Ŵ�С��������

//��ѯ�������ͼ�����б��е��±ꡣ��ͼ�鲻���б��У��򷵻�С��0������
	printf("Input the book number to be searched\n");
	scanf("%d", &book_no);
	index=query_list(list, total_book, book_no); 
	if(index>=0)
		printf("The name of book %d is %s\n", book_no, list[index].name);
	else
		printf("There is no book %d\n", book_no);

//�������ӵ�ͼ����Ϣ�����ͼ���Ѿ����б��У��򵥸���ͼ��������粻�ڣ���Ѹ�����ӵ�ͼ���б��У�������
	printf("Input the information of the new arrival book, including its book number, name, price and number of copies\n");
	scanf("%d%s%f%d", &new_book.no, new_book.name, &new_book.price, &new_book.num);
	total_book=insert_list(list, total_book, new_book);
	sort_list(list,total_book);
//��ӡ�б�������ͼ�����Ϣ
	printf("All books in store are shown below.\n");
	print_list(list, total_book);
	return 0;
}
struct book *input_list(struct book *list,int total_book){
	struct book *p;
	for(p=list;p<list+total_book;p++)
		scanf("%d%s %f%d",&p->no,p->name,&p->price,&p->num);
	return list;
}

struct book *sort_list(struct book *list,int total_book){
	int i=0,j=0;
	struct book temp;
	for(i=0;i<total_book;i++)
		for(j=0;j<total_book-1-i;j++)
			if(list[j].no>list[j+1].no){
				temp=list[j];
				list[j]=list[j+1];
				list[j+1]=temp;
			}
	return list;	
}
int query_list(struct book*list,int total_book,int book_no){
	int i;
	for(i=0;i<total_book;i++)
		if(list[i].no==book_no)
			return i;
	return -1;
}

int insert_list(struct book* list,int total_book,struct book new_book){
	int i,j;
	struct book temp;
	for(i=0;i<total_book;i++){
		if(list[i].no>new_book.no&&list[i-1].no<new_book.no){
			for(j=total_book-1;j>=i;j--)
				list[j+1]=list[j];
			list[i]=new_book;
			return total_book+1;
		}
		else if(list[i].no==new_book.no){
			list[i].num+=new_book.num;
			return total_book;
		}
	}
}
void print_list(struct book *list,int total_book){
	int i;
	for(i=0;i<total_book;i++)
		printf("%d %s %.1f %d\n",list[i].no,list[i].name,list[i].price,list[i].num);
}
