#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LENGTH 100//数组最大可用长度

struct configVar {
	int arrayLength;//数组有效长度
	int numsPerLine;
	char splitChar;
};

struct configVar cv;//全局变量

void config(void);//配置系统参数
void printMenu(void);//打印菜单
void clearCache(void);//清除缓冲区无用数据
void fillArray(int []);//生成样本数据
void printArray(int []);//显示数组
void deleteElement(int []);//删除
void deleteElementById(int [], int );//删除指定下标元素
void deleteElementByVal(int [], int) ;//删除指定值元素
void insert(int []);//插入
void search(int []);//查找
int simSearch(int [], int);//普通查找
int biSearch(int [], int , int, int);//二分查找
void sort(int []);//排列数组元素
void bubbleSort(int []);//冒泡排序
void selectSort(int []);//选择排序
void leftRotate(int []);//左旋数组

void config(void) {
	cv.splitChar = ' ';
	printf("请输入数组元素个数、每行输出元素个数（用空格隔开）：\n");
	scanf("%d %d",&cv.arrayLength,&cv.numsPerLine);//填空
	clearCache();
}

void printMenu(void) {
	printf("**********************************\n");
	printf("\t数组运算器功能菜单\t\n");
	printf("**********************************\n");
	printf("0、退出\n");
	printf("1、配置系统参数\n");
	printf("2、生成样本数据\n");
	printf("3、显示数组\n");
	printf("4、删除\n");
	printf("5、插入\n");
	printf("6、查找\n");
	printf("7、排列数组元素\n");
	printf("**********************************\n\n");
}

void clearCache(void) {
	while (getchar() != '\n')
		;
}

void fillArray(int a[]) {
	int i, var1, var2;
	char ch;
	while (1) {
		printf("++++++请选择菜单子选项++++++\n");
		printf("0)退出子菜单\n");
		printf("1)用指定范围的随机数填充数组\n");
		printf("2)键盘输入\n");
		printf("++++++++++++++++++++++++++++\n");
		scanf("%c", &ch);
		clearCache();
		if (ch == '0')
			break;
		switch (ch) {
			case'1':
				printf("请输入随机数的上下界（用空格隔开）：");
				scanf("%d%d", &var1, &var2);
				clearCache();
				srand(time(NULL));//初始化随机数发生器
				for(i=0;i<cv.arrayLength;i++)
					a[i]= rand() % ( var2- var1 + 1) + var1;//使用rand()函数，循环产生随机数并存入数组
				break;
			case'2':
				printf("请输入%d个整数：\n", cv.arrayLength);
				for(i=0;i<cv.arrayLength;i++)
					scanf("%d",&a[i]);//循环读取数据
				clearCache();
				break;
			default:
				break;
		}
	}
	printf("数组样本数据生成完毕！\n");
}

void printArray(int a[]) {
	int i;
	for (i = 0; i < cv.arrayLength; i++) {
		if (i%cv.numsPerLine==0&&i!=0) //填空，每行输出规定个数的数据
			printf("\n");
		printf("%d%c",a[i],cv.splitChar);//填空，输出数据和分隔符
	}
	printf("\n");
}

void deleteElement(int a[]) {
	int id, val;
	char ch;
	while (1) {
		printf("++++++请选择菜单子选项++++++\n");
		printf("0)退出子菜单\n");
		printf("1)删除指定下标的元素\n");
		printf("2)删除指定值的元素\n");
		printf("++++++++++++++++++++++++++++\n");
		scanf("%c", &ch);
		clearCache();
		if (ch == '0')
			break;
		switch (ch) {
			case'1':
				printf("请输入要删除的下标：");
				scanf("%d", &id);
				clearCache();
				deleteElementById(a,id) ;//填空，调用函数
				break;
			case'2':
				printf("请输入要删除的值：");
				scanf("%d", &val);
				clearCache();
				deleteElementByVal(a,val);//填空，调用函数
				break;
			default:
				break;
		}
	}
	printf("数组元素删除完毕！\n");
}

void deleteElementById(int a[], int id) {
	int i;
	if(id<cv.arrayLength&&id>0)
	{
		for(int i=id;i<cv.arrayLength;i++)
			a[i-1]=a[i];
	}
	cv.arrayLength=cv.arrayLength-1;
	for(i=0;i<cv.arrayLength;i++)
		printf("%d ",a[i]);
	printf("\n");
	//判断id的有效性
	//注意数组有效长度的变化
}

void deleteElementByVal(int a[], int val) {
	int id;
	while(1){
		id =simSearch(a,val);
		if(id==-1)
		{
			break;
			deleteElementById(a,id);
		}
	}
	//通过调用函数查找目标值的下标index
	//调用函数删除已找到下标的元素
	//要考虑多个目标值的情况
}

void insert(int a[]) {
	//考虑目前是否已达最大可用长度
	int pos, val,i;
	printf("请输入要插入的位置及元素值（用空格隔开）：");
	scanf("%d%d", &pos, &val);
	clearCache();
	if(pos<=cv.arrayLength-1)
	{
		for(i=cv.arrayLength-1;i>=pos-1;i--)
			a[i+1]=a[i];
		a[pos-1]=val;
		cv.arrayLength=cv.arrayLength+1;
		//插入
		//注意检查pos的有效性并考虑插入后数组有效长度的变化
		printf("数组元素插入完毕！\n");
		for(i=0;i<cv.arrayLength;i++)
			printf("%d ",a[i]);
	}
}

void search(int a[]) {//查找暂且可不考虑多个目标查找值的情况
	char ch;
	int val;
	printf("请输入要查找的值：");
	scanf("%d", &val);
	clearCache();
	while (1) {
		printf("++++++请选择菜单子选项++++++\n");
		printf("0)退出子菜单\n");
		printf("1)普通查找\n");
		printf("2)二分查找\n");
		printf("++++++++++++++++++++++++++++\n");
		scanf("%c", &ch);
		clearCache();
		if (ch == '0')
			break;
		switch (ch) {
			case'1':
				printf("%d",simSearch(a, val)); 	//填空，调用函数
					break;
			case'2': {
				bubbleSort(a); //先调用排序算法排序
				int low = 0;
				printf("%d",biSearch(a,val,low,cv.arrayLength-1));//填空，调用函数
				break;
			}
			default:
			break;
		}
	}
}


int simSearch(int a[], int val) {
	for(int i=0;i<cv.arrayLength;i++)
		if(a[i]==val)
			return i;
		return -1;
	//遍历的方式查找
	//返回值：找到：元素下标，未找到：-1
}

int biSearch(int a[], int val, int low, int high) {
	int mid=(low+high)/2;
	//对半处理数组
	if(low<=high)
	{
		if(a[mid]==val)
			return mid;
		else if(a[mid]<val)
			return  biSearch(a,val,mid+1,high);
		else if(a[mid]>val)
			return biSearch(a,val,low,mid-1);//要求使用递归
	}
	else 
		return -1;//返回值：找到：元素下标，未找到：-1
}

void sort(int a[]) {
	char ch;
	while (1) {
		printf("++++++请选择菜单子选项++++++\n");
		printf("0)退出子菜单\n");
		printf("1)冒泡排序\n");
		printf("2)选择排序\n");
		printf("3)左旋数组\n");
		printf("++++++++++++++++++++++++++++\n");
		scanf("%c", &ch);
		clearCache();
		if (ch == '0')
			break;
		switch (ch) {
			case'1':
				bubbleSort(a);	
					break;
			case'2':
				selectSort(a);	
					break;
			case'3':
				leftRotate(a);
					break;
			default:
				break;
		}
	}
	printf("排列完毕！\n");
}

void bubbleSort(int a[]) {
	int i,j,t;
	for(i=0;i<cv.arrayLength;i++)
		for(j=0;j<cv.arrayLength-i-1;j++)
			if(a[j]>a[j+1]){
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
	for(i=0;i<cv.arrayLength;i++)
		printf("%d ",a[i]);
}

void selectSort(int a[]) {
	int i,j,m=0,n;
	for(i=0;i<cv.arrayLength-1;i++){
		m=i;
		for(j=i+1;j<cv.arrayLength;j++)
			if(a[j]<a[m])
				m=j;
		n=a[i];
		a[i]=a[m];
		a[m]=n;
	}
	for(i=0;i<cv.arrayLength;i++)
		printf("%d",a[i]);
}

void leftRotate(int a[]) {
	int m,i,j,t;
	printf("请输入向左循环移位的位数：");
	scanf("%d", &m);
	clearCache();
	for(i=0;i<m%cv.arrayLength;i++){
			t = a[0];
			for (j = 1; j < cv.arrayLength; j++)
				a[j - 1] = a[j]; 
			a[cv.arrayLength-1] = t;
		}
	for(i=0;i<cv.arrayLength;i++)
		printf("%d ",a[i]);
	printf("左旋完毕！\n");
}
