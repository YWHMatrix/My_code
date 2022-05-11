#include <stdio.h>

void copy_arr(double ar1[],double ar2[],int n);
void copy_ptr(double *pt1,double *pt2,int n);
void copy_pts(double [],double [],double *pt3);
void show_arr (double ar0[],int n);
int main()
{
    double source[5] = {1.1,2.2,3.3,4.4,5.5};
    double target1[5];
    double target2[5];
    double target3[5];

    printf("target1:\n");
    copy_arr(target1,source,5);
    show_arr(target1,5);
    printf("target2:\n");
    copy_ptr(target2,source,5);
    show_arr(target2,5);
    printf("target3:\n");
    copy_pts(target3,source,source+5);
    show_arr(target3,5);

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


    
void copy_ptr(double *pt1,double *pt2,int n)
{
    for(int i=0;i<n;i++)
    {
        *(pt1+i)=*(pt2+i);
    }
  
}

void copy_pts(double ar4[],double ar5[],double *pt3)
{
    while(ar5<=pt3)
    {
        ar4[pt3-ar5-1]=ar5[pt3-ar5-1];
        pt3--;
    }
  
}
