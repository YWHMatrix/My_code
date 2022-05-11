#include <stdio.h>

void copy(int ar1[],int ar2[],int n);
void show(int ar3[],int n);
int main()
{
    int arr[7]={1,2,3,4,5,6,7};
    int arr1[3]; 
    copy(arr1,arr+2,3);
    show(arr1,3);
    return 0;
}

void copy(int ar1[],int ar2[],int n)
{
    for(int i=0;i<n;i++)
    {
        ar1[i]=ar2[i];
    }
}

void show(int ar3[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\n",ar3[i]);
    }
}
