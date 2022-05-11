#include <stdio.h>

int main()
{
    const int arr2[3][3]={
        {1,2,3},
        {4,5,5},
        {6,7,8}
    };
    const int (*pt1)[3];

    pt1=arr2;
    printf("%p\n",pt1[0]);
    printf("%p\n",pt1+1:q：);
    //printf("%p\n",pt1);
    //printf("%d\n",*(*(pt1+1)));
    //printf("%p\n",*(pt1+1));
    return 0;


}

