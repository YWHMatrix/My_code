//头文件
#ifndef _SList_H_
#include <stdio.h>
#include <stdlib.h>
#define MAX 100
typedef int ElemType;

typedef struct 
{
    ElemType data[MAX];
    int length;
}List;

void InitiList(List *L);
void InsertsList(List *L );
int InsertList(List *L,ElemType e, int n);
int Locate(List *L,ElemType e);
int GetElem(List *L,int n);
int  DeleteList(List *L,int n);
void printfList(List *L);
#endif 
