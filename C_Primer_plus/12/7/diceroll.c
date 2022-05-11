#include "diceroll.h"
#include <stdlib.h>
#include <stdio.h>

int rollem(int sdies)
{
    int roll;
    roll = rand() % sdies + 1;
    return roll;
}

int roll_n_dice(int dice, int sides)
{
    int tolo = 0;

    if(sides < 2)
    {
        printf("请输入大于或者等于2 的面数\n");

        return -2;
    }
    if(dice < 1)
    {
        printf("请输入大于或者等于1个筛子数\n");

        return -1;
    }
    
    for(int i = 0;i < dice ; i++)
    {
        tolo += rollem(sides);
    }
    return tolo;
 
}
