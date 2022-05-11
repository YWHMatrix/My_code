#include <stdio.h>
#include "hotel.h"

//菜单
int menu()
{
    printf("\n%s%s\n",STARS,STARS);
    printf("请输入酒店的对应的数字:\n");
    printf("1) 皇子酒店             2）德玛酒店\n");
    printf("3) 赵信酒店             4）蛮王酒店\n");
    printf("5) 退出");
    printf("\n%s%s\n",STARS,STARS);
    
    int choose;

  //  int first,second,third,fourth,quit;

    while(1)
    {
        choose=getint();

       if(choose>=1&&choose<=5)
       {
            break;    
       }
       else
           printf("请输入数字：1~5\n");
    }

    return choose;
}

//获取整数
int getint()
{
        int input;
        char ch;
        while(scanf("%d",&input)!=1)
        {
            while(ch=getchar()!='\n');
            {
                putchar(ch);
            }

            printf("请输入整数\n");
        }
        return input;
}

void showpirce(double price,int day)
{
    double sum=0.00;

    for(int n=0;n<day;n++)
    {
        sum+=price;
        price*=DISCOUNT;
    }
    printf("房费是：%0.2f.\n",sum);
}
