//SlinkList.h
//头文件
#ifndef _SlinkList_H_
#include <stdio.h>
#include <stdlib.h>
#define EOE -1
typedef int ElemType;
typedef struct node
{
    ElemType data;
    struct node *next;
}node;
typedef node * List;
List initiList (List *L);
List CreateListF(List L);
void printfList(List L);
int GetElem(List L, int i);
int Locate(List L,ElemType e);
int  InsElem(List L,int i,ElemType e);
int DelElem(List L,int i);
#endif // _SlinkList_H
