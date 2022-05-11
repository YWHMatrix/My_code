#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

int main()
{
    int send ;
    int num;
    int arr[11]={0};
    for(int i = 0;i < SIZE; i++ )
    {
        if(i % 100 == 0)
        {
            printf("请输入一个随机数种子\n");
            scanf("%d", &send);
            srand(send);
        }
        num = rand() % 10 + 1;
        switch(num)
        {
        case 1:
            arr[1]++;
            break;
        case 2:
            arr[2]++;
            break;
        case 3:
            arr[3]++;
            break;
        case 4:
            arr[4]++;
            break;
        case 5:
            arr[5]++;
            break;
         case 6:
            arr[6]++;
            break;
         case 7:
            arr[7]++;
            break;
         case 8:
            arr[8]++;
            break;
         case 9:
            arr[9]++;
            break;
         case 10:
            arr[10]++;
            break;
        default:
            printf("程序异常!");
        }

    }
    for(int j = 1; j < 11 ; j++)
        printf("%d  ", arr[j]);
    printf("\n");
    return 0;
}

