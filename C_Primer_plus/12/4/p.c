#include <stdio.h>

void fu();

int cons;

int main()
{
    while(1)
    {
        if(cons == 10)
            break;
        fu();      
    }

    printf("%d\n", cons);
    return 0;
}

void fu()
{
    cons++;
}
