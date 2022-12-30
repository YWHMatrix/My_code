#include <stdio.h>
#include <stdlib.h>
#include "DliskList.h"

DliskList InitList(DliskList *L)//初始化双链表
{
    (*L)=(DliskList *)malloc(sizeof(DliskList));
    (*L)->prior=(*L)->next=NULL;
    return (*L);
}

