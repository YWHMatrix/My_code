#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *dp , *fp;
    int  ch;
    if(argc != 3)
    {
        printf("Usage : %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[1] , "r")) == NULL )
    {
        printf("Can't open %s \n" , argv[1]);
        exit(EXIT_FAILURE);
    }
    if((dp = fopen(argv[2] , "w")) == NULL )
    {
        printf("Can't open %s \n" , argv[2]);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF)
    {
        putc(ch,dp);
    }
    fclose(fp);
    fclose(dp);
    return 0;
}

