#include <stdio.h>

struct month {
    char month_name[4];
    int month_day;
    int month_number;

};

int main(int argc , char *argv[])
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
    int sum = 0;
    int y , m , d;
    printf("请输入 年 月 日，例如：2020 3 26 \n");
    scanf("%d %d %d", &y, &m, &d);

    if(m < 0 || m > 12 || d < 0 || d > 31 )
        printf("请输入正确的日期\n");

    if((y % 400 == 0 && y % 100 == 0) || y % 4 == 0 ) //判断是否为闰年
        sun[1].month_day ++;

    for(int i = 0; i < m; i++)
    {
        if(i+1 == m)
            sum += d;
        else
            sum += sun[i].month_day;
    }
    
    printf("%d\n", sum);

    return 0;
}

