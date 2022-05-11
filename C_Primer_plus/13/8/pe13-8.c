#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void find(FILE *, int );

int main(int argc , char *argv[])
{
    FILE *fp;
    int ch;
    int count = 0;
    if(argc < 2)
    {
        fprintf(stderr,"Uages: %s file\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if(strlen(argv[1]) != 1)
    {
        printf("The second parameter is a character\n");
        exit(1);
    }
    if(argc == 2)
    {
        while((ch = getc(stdin)) != '\n')
        {
            if((char)ch == *argv[1])
            {
                count++;
            }
        }
        printf("stdin file %s character occurrences %d\n",argv[1],count);
    }
    else
    {
        for(int i = 2;i < argc; i++)
        {
           if((fp = fopen(argv[i] , "r")) == NULL)
           {
               printf("Can't open %s" , argv[i]);
               continue;
           }
           while((ch = getc(fp)) != EOF)
           {
               if((char)ch == *argv[1])
               {
                   count++;
               }
           }
           printf("%s file %s character occurrences %d\n",argv[i],argv[1],count);

        }
    }
    return 0;
}

