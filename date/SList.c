#include <stdio.h>
#include "SList.h"
 
void InitiList(List *L)//初始化链表
{
    L->length=0;
}

void InsertsList(List *L )//按多元素插入
{
    int n;
    ElemType e;
    printf("输入要插入元素的个数：");
    scanf("%d",&n);
    for (int  i = L->length; i < n; i++)
    {
        printf("输入元素：");
        scanf("%d",&e);
        L->data[i]=e;
        L->length++;
    } 
}
int InsertList(List *L,ElemType e, int n)//按指定位置插入,插入指定元素
{
    if(n<1||n>=L->length+1)
    {
        return 0;
    }
         for ( int i=L->length ; i>n ; i--)
         {
             L->data[i]=L->data[i-1];
         }
       
         L->data[n]=e;
         L->length++;
}
int Locate(List *L,ElemType e)//按值查找
{
    int i=0;
    while(i>L->length||L->data[i]!=e)
    {
        i++;
    }
       if (i>=L->length)
       {
           return 0;
       }
       else
       {
           return (i+1);
       } 
}

int GetElem(List *L,int n)//按位查找
{
    if (n>L->length)
    {
        return 0;
    }
     else
     {
         return L->data[n-1];
     }
}
int  DeleteList(List *L,int n)//删除某位元素
{
    if (n>L->length||n<1)
    {
        return 0;
    }
    for (int  i = n; i < L->length; i++)
    {
        L->data[i-1]=L->data[i];
    }
    L->length--;
}

void printfList(List *L)//打印元素
{
    for (int i = 0; i <L->length; i++)
    {
    printf("%d",L->data[i]);
    }
}
/*int main() {
    List L;
    InitiList(&L);
    InsertsList(&L);
    InsertList(&L,19,2);
    printf("按值查找的元素：%d\n", Locate(&L,2));
    printf("按位查找的元素：%d\n",GetElem(&L,2));
    DeleteList(&L,3);
    printfList(&L);
    return 0;
    */

