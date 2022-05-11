#include <stdio.h>

int sum(const int ar[],int n);

int main()
{
    int arr[2]={1,2};
    sum(arr,2);

    return 0;
}

int sum(const int ar[],int n)
{
    int i;
    int total=0;
    for(i=0;i<n;i++)
    {
        total+=ar[i]++;
    }
    return total;
}
