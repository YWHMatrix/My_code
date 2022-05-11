#include <stdio.h>
#include <string.h>

struct month {
    char month_name[4];
    int month_day;
    int month_number;

};

int main()
{
    struct month sun[12] = {
        {"Jan",31,1},
        {"Feb",28,2},
        {"Mar",31,3},
        {"Apr",30,4},
        {"May",31,5},
        {"Jun",30,6},
        {"Jul",31,7},
        {"Aup",31,8},
        {"Sep",30,9},
        {"Oct",31,10},
        {"Nov",30,11},
        {"Dec",31,12}
    };
    char name_s[10];
    int number = 0;
    int sum = 0;
    scanf("%s",name_s);   
    for(int i = 0; i < 12; i++)
    {
        if(strcmp(name_s,sun[i].month_name) == 0)
        {
            number = i;
            break;
        }
        else
        {
            printf("请输入正确的三位月份名缩写，例如：Jan,Feb、\n");
        }
    }
    for(int i = 0; i < 12; i++)
    {
            if(i <= number)
            {
                sum += sun[i].month_day;
            }
    }
    printf("%d", sum);

    return 0;
}

