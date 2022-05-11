#include <stdio.h>
#include <stdlib.h>


int main(int argc , char * argv[])
{
    FILE *F1,*F2;
    int ch;
    int CH;
    if(argc != 3)
    {
        printf("Usage : %s filename \n", argv[0]);
        exit(1);
    }
    if((F1 = fopen(argv[1], "r")) == NULL)
    {
        printf("can't open %s \n", argv[1]);
        exit(2);
    }
    if((F2 = fopen(argv[2], "r")) == NULL)
    {
        printf("can't open %s \n", argv[2]);
        exit(3);
    }
    while(1)
    {
        while((ch = getc(F1)) != '\n')
        {
            if(feof(F1))
                break;
            putchar(ch);
        }
        while((ch = getc(F2)) != '\n')
        {
            if(feof(F2))
                break;
            putchar(ch);
        }
        if(feof(F1) && feof(F2))
            break;

        printf("\n");
    }

    fclose(F1);
    fclose(F2);
    
    return 0;
}

