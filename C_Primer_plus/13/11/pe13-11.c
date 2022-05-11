#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 255

int main(int argc , char *argv[])
{
    
    FILE *fp;
    char temp[MAX];

    if(argc != 3)
    {
        printf("parameter is wrong\n");
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[2],"r")) == NULL)
    {
        printf("Can't open %s file\n", argv[2]);
        exit(2);
    }
    
    
    while(fgets(temp,MAX,fp) != NULL)
    {
       if( strstr(temp,argv[1]) != NULL)
       {
           fputs(temp,stdout);
       }
    }
    if(fclose(fp) != 0)
        printf("file close failed\n");

    return 0;
}

