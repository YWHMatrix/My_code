#include <stdio.h>

void copy(int N,int M,double arr_source[N][M],double arr_target[N][M]);
void show(int N,int M,double arr_2[N][M]);
int main()
{
    int N=3;
    int M=5;
    double arr2[3][5]={
        {1.0,2.0,3.0,4.0,5.0},
        {1.0,2.0,3.0,4.0,5.0},
        {1.0,2.0,3.0,4.0,5.0}
        
    };
    double arr3[N][M];
    copy(N,M,*arr2,*arr3);
    show(N,M,arr3);
    return 0;
}

void copy(int N,int M,double arr_source[N][M],double arr_target[N][M])
{
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
        {
            arr_target[i][j]=arr_source[i][j];
        }
}
void show(int N,int M,double arr_2[N][M])
{
    for(int i=0;i<N;i++)
    {

    for(int j=0;j<M;j++)
        {
            printf("%1.f",arr_2[i][j]);
        }
    printf("\n");
    }

}

