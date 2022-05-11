#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "diceroll.h"

int main()
{

    int num;
    int roll;
    int sides , dice;

    srand((unsigned int )time(0));
    
    printf("Enter the number of sets? enter q to stop:");
    while(scanf("%d", &num) == 1 )
    {
        printf("How many sides and how many dice? ");
        scanf("%d %d", &sides , &dice);
        printf("Here are %d sets of %d %d-sided throws.\n", num, dice , sides);
        for(int i = 0; i < num; i++)
        {
            roll = roll_n_dice(dice,sides);
            
            printf("%-4d", roll);

            if((i+1) % 10 == 0)
                printf("\n");
        }
        printf("\n");
        printf("Enter the number of sets? enter q to stop:");
    }

    return 0;
}

