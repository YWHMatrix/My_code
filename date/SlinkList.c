//基础版单链表
#include <stdio.h>
#include "SlinkList.h"
List  initiList(List* L)
{
	(*L) = (node*)malloc(sizeof(node));
	(*L)->next = NULL;
	return (*L);
}

List CreateListF(List L)//初次头插，不进行判断
{
	node* p;
	int n,e;
	printf("输入要插入元素的个数：");
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
	   p = malloc(sizeof(struct node));
	   if (!p)exit(EOE);
	   scanf("%d",&e);
	   p->data = e;
	   p->next = L->next;
	   L->next = p;
	}
	return L;
}

List CreateListR(List L) 
{
	node *p;
	p=(node*)malloc(sizeof(node));//创造一个指针始终指向表尾，除初次
	p=L;
	node *q;
	int  n,e;
	printf("请输入要插入元素的个数：");
	scanf("%d",&n);
	for (int  i = 0; i < n; i++)
	{
	q=(node *)malloc(sizeof(node));
	scanf("%d",&e);
	q->data=e;
	p->next=q;
	p=q;
	}
	p->next=NULL;
	return L;
}
void printfList(List L)//打印链表
{
	node *p;
	p=L->next;
	while (p!=NULL)
	{
		printf("%d",p->data);
		p=p->next;
	}
	printf("\n");
}

int GetElem(List L, int i)//按位置查找
{
	int j=1;
	node *p=L;
	if (i<=0)
	{
		return 0;
	}
	while (p!=NULL&&j<=i)
	{
		p=p->next;
		j++;
	}
	if (p==NULL)
	{
		return 0;
	}
	else
	{
		return p->data;
	}
}

int Locate(List L,ElemType e)//按值查找
{
	int j=1;
	node *p=L;
	while (p!=NULL&&p->data!=e)
	{
		j++;
		p=p->next;
	}

	if (p==NULL)
	{
		return 0;
	}
	else
	{
		return (j);
	}	
}
int  InsElem(List L,int i,ElemType e)//插入一个元素
{
	int j=1;
	node *p=L;
	node *q;//
	if (i<=0)
	{
		return 0;
	}
	while (p!=NULL&&j<i)
	{
		j++;
		p=p->next;
	}
	if (p ==NULL)
	{
		return 0;
	}
	else
	{
		q=(node *)malloc(sizeof(node));
		q->data=e;//将元素放入新节点
		q->next=p->next;
		p->next=q;
	}
}
int DelElem(List L,int i)//删除节点
{
	int j=1;
	node *p=L,*q;
	if (i<=0)
	{
		return 0;
	}
	while (p!=NULL&&j<i)//要删除某个节点，就要找到前一个节点
	{
		j++;
		p=p->next;
	}
	q=p->next;//q指向将要删除的节点
	if (q==NULL)
	{
		return 0;
	}
	else
	{
	p->next=q->next;
	free(q);
	return 1;
	}
}

