#include <stdio.h>
#include "hotel.h"

int main()
{
    int day;//天数
    double price;//价格
    int choose;
    while((choose=menu())!=QUIT)
    {
         switch(choose)
         {
         case 1:price=HOTEL1;
                break;
         case 2:price=HOTEL2;
                break;
         case 3:price=HOTEL3;
                break;
         case 4:price=HOTEL4;
                break;
         default:price=0.0;
                 printf("Oops\n");
                break;
         }
        printf("请输入你要住宿的天数：");
        while(1)
        {
            if((day=getint())>0)
                break;
            else
                printf("请输入正确的天数\n");
        }
        showpirce(price,day);

    }
        
        printf("Thank you and goodbye.\n");

    return 0;
}

