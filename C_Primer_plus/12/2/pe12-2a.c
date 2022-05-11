#include <stdio.h>
#include "pe12-2a.h"

static int modes;      //模式
static double distance;   //距离
static double fuel;       //燃料

void set_mode(int mode)
{
    if(mode == 1|| mode == 0)
        modes =mode;
    else if(modes == 1)
        printf("Ivalid mode specifed .Mode %d(US) used.\n", modes);
    else
        printf("Ivalid mode specifed .Mode %d(Metric)used.\n", modes);
}

void get_info()
{
    printf("Enter distance tarveled in miles :");
    scanf("%lf",&distance);
    printf("Enter fuel consumed in gallons : ");
    scanf("%lf", &fuel);

}

void show_info()
{
    if(modes == 0)
        printf("Fuel consumption is %.2lf liters per 100 km.\n", (fuel/distance)*100);
    else
        printf("Fuel consumption is %.2lf miles per gallon.\n",distance/fuel);
}
