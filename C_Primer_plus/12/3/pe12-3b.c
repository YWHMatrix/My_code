#include <stdio.h>
#include "pe12-3a.h"

int main(int agrc, char *agrv[])
{
    int mode;       //输入模式
    int modes = 0;  //记录上一个模式
    double distance;
    double fuel;
    double *pt_d = &distance;
    double *pt_f = &fuel;

    printf("Enter 0 for metric mode,1 for US mode :");
    scanf("%d", &mode);

    while(mode >= 0 )
    {
        modes=set_mode(mode,modes);
        get_info(pt_d , pt_f);
        show_info(distance,fuel,modes);
        printf("Enter 0 for metric mode,1 for US mode :");
        printf("(-1 to quiu): ");
        scanf("%d", &mode);

    }
        printf("Done.\n");
    return 0;
}

