#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int count = 0;
    int i;
    for( i = 0; i < 5 ; i++)
    {
        if(count == 4)
            break;
        count++;
    }
    printf("%d",i);

    return 0;
}
