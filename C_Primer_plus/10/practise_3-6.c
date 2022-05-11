#include <stdio.h>

int arr_int(int ar[],int n);
int arr_double(double ar1[],int n);
double arr_dif(double ar2[],int n);
int main()
{
    int ar[3]={1,3,2};
    double arr1[3]={1.0,4.0,5.0};
    int num;
    double dnum;
    num=arr_int(ar,3);
    printf("%d\n",num);
    num=arr_double(arr1,3);
    printf("%d\n",num);
    dnum=arr_dif(arr1,3);
    printf("%.1f\n",dnum); 
    return 0;
}

int arr_int(int ar[],int n)
{
    int i;
    int j;
    i=ar[0];
    for(j=0;j<n;j++)
    {
        if(ar[j]>i)
        {
            i=ar[j];
        }
    }
    return i;
}

int arr_double(double ar1[],int n)
{
    double i;
    int j;
    i=ar1[0];
    for(j=0;j<n;j++)
    {
        if(ar1[j]>i)
        {
            i=ar1[j];
        }
    }

    return j;
}


double arr_dif(double ar2[],int n)
{
    double max,min;
    int j;
    max=ar2[0];
    min=ar2[0];
    for(j=0;j<n;j++)
    {
        if(ar2[j]>max)
        {
            max=ar2[j];
        }
        if(ar2[j]<min)
        {
            min=ar2[j];
        }
    }
    
    return max-min;

}
