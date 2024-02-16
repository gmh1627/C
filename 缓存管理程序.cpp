#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
//���п��С���ֽڣ�
# define BLOCK_SIZE 32
//���п�����
# define BLOCK_NUM 10
//��������С���ֽڣ�����BLOCK_NUM���ڴ�鹹��
# define POOL_SIZE (BLOCK_SIZE * BLOCK_NUM)
//��ָ�����Ͷ���
typedef unsigned char(*Tblkptr) [BLOCK_SIZE];
//���������Ͷ���
typedef struct{
		void*poolAddress;//��������ʼָ��
		Tblkptr blockListHead; //�������Ŀ��п�����ͷָ��
		int nFreeBlocks;//���п�����
	}Tpool;
//����������
int initMemPool (Tpool * ,int);
void * getBlock(Tpool *);
void putBlock (Tpool * ,void * );
void printBlockList(Tpool * pool);
//��ʼ���������ĺ�����
int initMemPool (Tpool *pool, int size){
	//��Ĵ���
	}
//����������е�ǰ���п�����(���ַ��;
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
//����һ�����п飬���ؿ�ָ�룺
void * getBlock(Tpool * pool){
	//��Ĵ���
}

//����һ���ڴ�鵽��������
void putBlock(Tpool * pool,void *p){
	//��Ĵ���
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
//ʹ�÷��亯���ķ�ʽ������
	pl=getBlock(&memPool);//����1
	printf("����һ���ڴ��1��\n");
	printBlockList (&memPool);
	p2=getBlock(&memPool);//����2
	printf("����һ���ڴ��2��\n");
	printBlockList (&memPool) ;
	p3=getBlock (&memPool) ;//����3
	printf("����һ���ڴ��3��\n");
	printBlockList (&memPool);
	putBlock(&memPool,p2);//����2
	printf("�����ڴ��2��\n");
	printBlockList (&memPool);
	putBlock(&memPool,p3);//����3
	printf("�����ڴ��3��\n");
	printBlockList (&memPool);
	putBlock(&memPool,p1);//����1
	printf("�����ڴ��1��\n");
	printBlockList (&memPool);
	free((void *)(memPool.poolAddress));
	return 0;
}
