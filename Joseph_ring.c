#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct Node
{
    int num;
    struct Node *next;
}LinkList;
LinkList *creat(int n)
{
    int i = 1;
    LinkList *p,*q,*head;
    p = (LinkList*)malloc(sizeof(LinkList));
    p->num = i;
    head = p;
    for(i = 2;i<=n;i++)
    {
        q = (LinkList*)malloc(sizeof(LinkList));
        q->num = i;
        p->next = q;
        p = q;
    }
    p->next = head;//连接
    return head;
}
void fun(LinkList *L,int k,int m)
{
    int i,j;
    LinkList *p,*q,*s;
    p = L;
    for(i = 1;i<k;i++)
    {
        q = p;
        p = p->next;
    }//找到第k个人
    while(p->next!=p)
    {
        for(j = 1;j<m;j++)
        {
            q=p;
            p = p->next;
        }//此时找到了
        printf("%5d",p->num);
        s = p;
        q->next = p->next;
        p = p->next;
        free(s);
    }
    printf("%5d",p->num);
}
int main()
{
    LinkList *L;
    int n,k,m;
    n = 9;
    m = 4;//从第k个人开始 从数字一报到m 每报到m的人死亡
    k = 2;
    L=creat(n);
    fun(L,k,m);
return 0;
}
