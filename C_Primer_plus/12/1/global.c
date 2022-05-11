#include <stdio.h>

void critc(int *);

int main()
{
    int units = 0;
    int *pt = &units;
    puts("How many pounds to a firkin of buttere?");

    scanf("%d", &units);
    while(units != 56)
    {
        critc(pt);
    }
    
    puts("You must have looked it up");

    return 0;
}

void critc(int *p)
{
    puts("NO luck, my friend. Try again.");
    scanf("%d", p);
}
