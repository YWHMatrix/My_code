#include <stdio.h>

#define MONTHS 12
#define YEARS 5

int main()
{
    const  float rain[YEARS][MONTHS]={
        {4.3,4.3,4.3,3.0,2.0,1.2,0.2,0.2,0.4,2.4,3.5,6.6},
        {8.5,8.2,1.2,1.6,2.4,0.0,5.2,0.9,0.3,0.9,1.4,7.3},
        {9.1,8.5,6.7,3.3,0.8,0.2,1.1,2.3,6.2,0.2,3.3,4.5},
        {8.2,1.5,6.5,3.2,0.8,0.6,1.2,3.3,5.5,6.3,0.2,3.2},
        {5.2,5.3,0.2,3.0,0.5,1.2,1.6,3.2,8.3,0.2,0.3,0.6},
   };
    const float (*pt1)[MONTHS]=rain;
    int year , month;
    float subtot ,total;
    
  //  printf("  YEAR     RAINFALL (inches)\n");
    for(year = 0,total = 0; year < YEARS;year++)//年
    {
        for(month = 0, subtot = 0;month < MONTHS; month++)//月
        {
            subtot+= *(*(pt1+year)+month);

        }
   //     printf("\n");
        total+= subtot;
    }
    printf("%.1f\n",total/YEARS);
    return 0; 
}

