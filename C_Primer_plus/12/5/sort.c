#include <stdio.h>
#include <stdlib.h>
#include "rand1.h"
#define SIZE 100

void randome(int ar[]);
void sort(int ar[]);
void show(int ar[]);

int main()
{
    int arr[SIZE];
    randome(arr);
    sort(arr);
    show(arr);
    return 0;
}

void randome(int ar[])
{
    for(int i = 0;i < SIZE;i++)
    {
        /* ar[i] = rand() % 10 + 1; */
        ar[i] = rand1() %10 + 1;//移植随机算法
    }
}

void sort(int ar[])
{
    int temp = 0;
    for(int  i = 1;i < SIZE; i++)
        for(int j = 0; j < SIZE - 1; j++)
        {
            if(ar[j] < ar[j+1])
            {
                temp = ar[j];
                ar[j] = ar[j+1];
                ar[j+1] = temp;
            }
        }
}

void show(int *ar)
{
    for(int i = 0; i < SIZE; i++)
    {
        printf("%d  ", ar[i]);        
        if(ar[i] < 10)
            printf(" ");
        if((i+1)%10==0)
            printf("\n");
    }
}
