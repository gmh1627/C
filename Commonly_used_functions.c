#include <stdio.h>
#include <stdlib.h>		//包含malloc等函数。也可用#include <malloc.h>代替 

//折半查找（升序） 
int binarySearch(int a[], int n, int key){	//传入参数为升序数组a，数组长度n和查找值key 
	int mid, low = 0, high = n - 1;
	while(low <= high){
		mid = (low + high) / 2;
		if(key < a[mid])
			high = mid - 1;
		else if(key > a[mid])
			low = mid + 1;
		else
			return mid;
	}
	return -1;
}

//把数组逆序输出
/*	int i,n=10,p[10]={1,2,3,4,5,6,7,8,9,10},*t,k,*s;
	s=p;
	t=s+9;
	while(s<t)
	{
		k=*s;
		*s=*t;
		*t=k;
		++s;
		--t;
	}
	for(i=0;i<10;i++)
		printf("%d",p[i]);*/
		
//字符串长度
int myStrlen(const char str[]) {
	int len = 0;
	while (str[len] != '\0')
		++len;
	return len;
}

//字符串比较
int myStrcmp(char s1[], const char s2[]) {
	int i;
	for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; ++i);
	return s1[i] - s2[i];
}

//字符串连接
char* myStrcat(char s1[], const char s2[]) {
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i);
	for (j = 0; (s1[i] = s2[j]) != '\0'; ++i, ++j);
	return s1;
}

//字符串拷贝
char* myStrcpy(char s1[], const char s2[]) {
	int i;
	for (i = 0; (s1[i] = s2[i]) != '\0'; ++i);
	return s1;
}

//向右循环移位
void rightRotate(char *a,int n) {
	int m,i,j,t;
	printf("请输入向右循环移位的位数：");
	scanf("%d", &m);
	for(i=0;i<m%n;i++)
	{
		t = a[n-1];
		for (j = n-2; j >=0; j--)
			a[j+1] = a[j]; 
		a[0] = t;
	}
	for(i=0;i<n;i++)
		printf("%c ",a[i]);
}

typedef struct node{
	int num;
	struct node* next;
}Node;	//typedef给类型起别名，写起来更加简单。#define也可以但typedef更好 

//头插法建立链表
//链表内元素顺序与输入数据顺序相反，如 输入1 2 3 0(结束)，链表 head->3->2->1->NULL  
Node* CreateList_head(){
	Node *head = NULL, *p;					//头指针head = NULL置空链表 
	int no;
	printf("输入 ");						//打印提示信息，必要时可以省略，节约时间 
	scanf("%d", &no);						//输入循环控制数据 
											//应先输入控制数据然后再申请结点，否则结束时会多分配结点，使操作冗余甚至浪费空间 
	while(no){							//当输入数据值不是结束标志
											//这里将0作为结束标志，为避免引起歧义，需通过注释或打印信息指明结束标志是什么。 
		p = (Node*)malloc(sizeof(Node));	//申请新结点，用指针p指向该结点 
		p->num = no;						//给新结点赋予相关数据值，p->num也可写为(*p).num)
		/* scanf输入其他信息如姓名、性别、学号等 */
		p->next = head;						//新结点指针域指向原表头结点
		head = p;							//新结点插入表头
		printf("输入 ");
		scanf("%d", &no);					//输入循环控制数据 
	}
	return head;
}

//尾插法建立链表
//链表内元素顺序与输入数据顺序相同，如 输入1 2 3 0(结束)，链表 head->1->2->3->NULL
Node* CreateList_tail(){
	Node *head = NULL, *rear = NULL, *p;			//头指针head = NULL置空链表，尾指针rear
	int no;
	printf("输入 ");
	scanf("%d", &no);						//输入循环控制数据 
	while(no){							//当输入数据值不是结束标志
		p = (Node*)malloc(sizeof(Node));	//申请新结点，用指针p指向该结点 
		p->num = no;						//给新结点赋予相关数据值
		/* scanf输入其他信息如姓名、性别、学号等 */
		if(!head)					//如果链表为空 
			head = p;					 	//表示新插入的结点是首结点，头指针指向首结点
		else
			rear->next = p;					//否则将新结点插入到尾指针指向的结点之后
		rear = p;							//使尾指针指向新结点
		printf("输入");
		scanf("%d", &no); 					//输入循环控制数据 
	} 
	if(rear)
		rear->next = NULL;
	return head;
}

//遍历链表（以打印为例）
void PrintList(Node* head){
	Node* p = head;
	while(p){
		printf("%d\n", p->num);				// 执行操作
		p = p->next;
	}
}

//寻找结点
Node* ListSearch(Node* head, int no){		//这里返回类型Node*是考虑到寻到结点后可能对该结点有后续操作，因此返回指针；若未寻到返回NULL 
	Node* p = head;
	while(p){
		if(p->num == no)
			break;
		p = p->next;
	} 
	if(!p)
		printf("未找到该结点，返回NULL\n");
	return p;
} 

//插入结点
//先找位置，后插入 
//插入核心操作：
/*
	//s为指向待插入结点的指针，p为指向插入位置前一个结点的指针 
	s->next = p->next;
	p->next = s;
*/ 

Node* ListInsert_ascending(Node *head, Node *ps){		//传入参数是链表头指针head和指向待插入结点的指针ps 
	Node *p,*q;
	//情况1 
	if(!head){						//如果链表为空，则待插入结点即为头结点，头指针指向该结点
		ps->next = NULL;
		return ps;							//函数结束，返回头指针 
	}
	//情况2 
	if(ps->num <= head->num){				//若待插入结点的数据小于等于头结点的数据，按升序应插入第一个位置 
		ps->next = head;					//ps->next指向原头结点  
		return ps;							//待插入节点成为新的头结点，返回头指针 
	}
	//情况3 
	p = q = head;							//p用来指向当前与*ps比较的结点，q用来保存p的前驱结点 
	while(p  && p->num < ps->num){	//当p != NULL且p当前指向结点的数值小于待插入结点的数值 
											//注意 && 两边的表达式不能交换，因为当p = NULL时引用p->num会出错 
		q = p;								//q前移，也可写为 q = q->next; 修改后可以与后一句交换顺序，否则不能 
		p = p->next;						//p前移 
	}										//循环结束，q指向应插入结点的前一个位置，p指向应插入结点的后一个位置（当*ps数据大于链表所有元素时p = NULL） 
	q->next = ps;							//插入结点 
	ps->next = p;
	return head;							//函数结束，返回头指针 
}
Node* ListInsert_position(Node* head, Node* ps, int pos) {	//传入参数是链表头指针head，指向待插入结点的指针ps和插入位置pos 
	if (pos == 1) {							//若插入到链表第一个位置 
		ps->next = head;
		return ps;
	}
	int i = 1;
	Node* p = head;
	while (p && i < pos - 1) {
		p = p->next;
		i++;
	}
	if (!p || i >= pos) {			//前者意味着pos > Length，后者意味着pos < 1 
		printf("位置错误，插入失败，返回原链表\n");
		return head;
	}
	ps->next = p->next;						//插入结点 
	p->next = ps;
	return head;
}
//3.插入结点到链表指定结点之后
Node* ListInsert_xnode(Node *head, Node *ps, int no){		//传入参数是链表头指针head，指向待插入结点的指针ps和指定结点的数值no 
	Node *p = ListSearch(head, no);
	if(!p)
		printf("该结点不存在，插入失败，返回原链表\n");
	else{
		ps->next = p->next;					//插入结点 
		p->next = ps;
	}
	return head; 
} 

//删除指定结点 
//先找位置，后删除 
//删除核心操作：
/*
	//p为指向待删除结点的指针，q为指向其前驱结点的指针 
	q->next = p->next;
	free(p);
*/ 
Node* ListDelete(Node *head, int no){
	Node *p,*q;
	if(head->num == no){					//若删除结点为头结点 
		p = head;							//p保存当前结点 
		head = p->next;						//头指针指向当前第二个结点（有可能为NULL） 
		free(p);							//释放p指向空间 
		return head;						//函数结束，返回头结点 
	} 
	q = p = head;							//p指向当前比较结点，q指向其前驱结点 
	while(p && p->num != no){		//注意 && 两边的表达式不能交换，因为当p = NULL时引用p->num会出错 
		q = p;								//q前移 
		p = p->next;						//p前移 
	}
	if(p){							//说明找到待删除结点 
		q->next = p->next;					//删除结点 
		free(p);
	}
	else printf("未找到该结点，删除失败，返回原链表\n");
	return head;
}

//销毁链表 
Node* ListDistroy(Node *head){
	Node *p = head, *temp;
	while(p){
		temp = p;
		p = p->next;
		free(temp);
	}
	return NULL;
} 

int main(){
	Node* head = CreateList_tail();
	/*
	while (1) {
		PrintList(head);
		int pos;
		Node* p = (Node*)malloc(sizeof(Node));
		scanf("%d%d", &p->num, &pos);
		ListInsert_position(head, p, pos);
	}
	*/
	return 0;
} 
