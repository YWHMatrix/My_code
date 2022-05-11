#include <stdio.h>

void copy_arr(double ar1[],double ar2[],int n);
void show_arr (double ar0[],int n);
int main()
{
    double arr3[2][2]={{1.2,2.2},{3.2,4.2}};
    double arr4[2][2];
    double *pt1,*pt2,*pt3;
    pt1=*arr3;
    pt2=*arr4;
    pt3=*arr4;
    for(int i=0;i<2;i++)
    {
        copy_arr(pt2,pt1,2);
        pt1=pt1+1;
        pt2=pt2+1;
    }
    for(int i=0;i<2;i++)
    {
        show_arr(pt3,2);
        pt3++;
    }
 
    return 0;
}
void show_arr (double ar0[],int n)
{
    int i=0;
    for(i;i<n;i++)
    {
        printf("%.1f ",ar0[i]);
    }
    printf("\n");
}

void copy_arr(double ar1[],double ar2[],int n)
{
    int i=0;
    for(i;i<n;i++)
    {
        ar1[i]=ar2[i];
    }
} 
