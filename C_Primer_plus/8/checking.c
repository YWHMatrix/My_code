//求a到b的平方和
#include <stdio.h>
#include <stdbool.h>

int get_int();
bool bad_limit(int MIN,int MAX,int upper,int lower);
int sum_square(int lower,int upper);

int main(int argc,char *argv[])
{
    
    const int MIN=-1000;
    const int MAX=1000;
    
    int lower;
    int upper;
    while(1)
    {
            printf("请输入下限:");
            lower=get_int();
            printf("请输入上限:");
            upper=get_int();

            if(upper!=0||lower!=0)
            {
                if(bad_limit(MIN,MAX,upper,lower))
                    printf("请输入合理的上限和下限\n");
                else
                    printf("%d\n",sum_square(lower,upper));
            }        
            else
                break;
        }
    return 0;

}

int get_int()
{
    int input;
    char ch;
    
    while(scanf("%d",&input)!=1)//如果不是整数进行处理
    {
        int ch;
            while((ch=getchar())!='\n')
            {
                putchar(ch);
            }
            printf("请输入正确的数字:\n");
    }

    return input;
}

bool bad_limit(int MIN,int MAX,int upper,int lower)
{
    //判断上限和下限是否合法
    bool not_good=false;
    
    if(MAX<MIN)
        not_good=true;
    if(MAX<upper||upper<lower)
        not_good=true;
    if(lower<MIN||upper<MIN)
        not_good=true;
    return not_good;
}

int sum_square(int lower,int upper)
{
    int sum=0;
    for(int i=lower;i<=upper;i++)
    {
        sum+=i*i;
    }
    return sum;
}














