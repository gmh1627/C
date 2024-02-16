#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//空闲块大小（字节）
# define BLOCK_SIZE 32
//空闲块数量
# define BLOCK_NUM 10
//缓存区大小（字节），由BLOCK_NUM个内存块构成
# define POOL_SIZE (BLOCK_SIZE * BLOCK_NUM)
//块指针类型定义
typedef unsigned char(*Tblkptr) [BLOCK_SIZE];
//缓存区类型定义
typedef struct{
		void*poolAddress;//缓存区起始指针
		Tblkptr blockListHead; //缓存区的空闲块链表头指针
		int nFreeBlocks;//空闲块数量
	}Tpool;
//函数声明：
int initMemPool (Tpool * ,int);
void * getBlock(Tpool *);
void putBlock (Tpool * ,void * );
void printBlockList(Tpool * pool);
//初始化缓存区的函数：
int initMemPool (Tpool *pool, int size){
	//你的代码
	}
//输出缓存区中当前空闲块链表(块地址）;
void printBlockList(Tpool * pool){
	Tblkptr *pblink;
	int i=0;
	if (! pool->blockListHead){
		printf("null list.\n");
		exit (0);
	}
pblink= (Tblkptr *)pool->blockListHead;
while (pblink){
	printf("block#8 2d,address:0X%p\n",i++,pblink);
	printf ("\tnext->\t%p\n", (void *) (*pblink));
	pblink =(Tblkptr *)(*pblink);
}
	printf("----- \n\n");
}
//分配一个空闲块，返回块指针：
void * getBlock(Tpool * pool){
	//你的代码
}

//回收一个内存块到缓存区：
void putBlock(Tpool * pool,void *p){
	//你的代码
}
int main(){
	Tpool memPool;
	void *pl,*p2,*p3;
	int status;
	status= initMemPool (&memPool, POOL_SIZE);
	if (status)
		printBlockList (&memPool);
	else{
		printf("memory allocation failed. \n");
		exit (0);
	}
//使用分配函数的方式举例：
	pl=getBlock(&memPool);//请求1
	printf("请求一个内存块1。\n");
	printBlockList (&memPool);
	p2=getBlock(&memPool);//请求2
	printf("请求一个内存块2。\n");
	printBlockList (&memPool) ;
	p3=getBlock (&memPool) ;//请求3
	printf("请求一个内存块3。\n");
	printBlockList (&memPool);
	putBlock(&memPool,p2);//回收2
	printf("回收内存块2。\n");
	printBlockList (&memPool);
	putBlock(&memPool,p3);//回收3
	printf("回收内存块3。\n");
	printBlockList (&memPool);
	putBlock(&memPool,p1);//回收1
	printf("回收内存块1。\n");
	printBlockList (&memPool);
	free((void *)(memPool.poolAddress));
	return 0;
}
