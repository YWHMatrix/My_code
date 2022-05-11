#include <stdio.h>
//简易版猜数字游戏

int main()
{
    int guess = 1;
    char respones;
    printf("请猜1到100之间的数字\n");
    printf("如果才对了就输入'y',如果猜错了就输入'n'\n");
    printf("数字是%d\n",guess);
    while((respones=getchar())!='y')
    {
        if(respones=='n')
            printf("数字是%d\n",++guess);
        else
            printf("请输入'y'或者'n'\n");
        while(getchar()!='\n')//消化掉回车键
            continue;
    }
    printf("恭喜你猜对了\n");
    
   return 0; 
}
