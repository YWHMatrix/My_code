#include <stdio.h>

void pt(int ar1[],int ar2[],int *pt1);

int main()
{

    int ar3[2];
    int ar4[2]={3,4};
    pt(ar3,ar4,ar4+2);

    for(int i=0;i<2;i++)
    {
        printf("%d",ar3[i]);
    }
    return 0;
}

void pt(int ar1[],int ar2[],int *pt1)
{
    int i=0;
    while(ar2<=pt1)
    {
        i=pt1-ar2;
        ar1[i-1]=ar2[i-1];
        pt1--;
    }

}
