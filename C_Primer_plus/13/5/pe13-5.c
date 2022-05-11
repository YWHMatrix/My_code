#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BULSIZE 4096
#define SIZE 81 

void addpend(FILE *scurce, FILE *dest);

int main(int argc, char *argv[])
{
    FILE *fa, *fs;
    if(argc < 3)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if((fa = fopen(argv[1], "a+")) == NULL)
    {
        printf("Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if(setvbuf(fa,NULL,_IOFBF,BULSIZE) != 0)
    {
        printf("Can't create output buffen\n");
        exit(EXIT_FAILURE);
    }       
    for(int i = 2;i < argc; i++)
    {
        if(strcmp(argv[1],argv[i]) == 0)
            fputs("Can't append file to itself\n", stderr);
       else if((fs = fopen(argv[i],"r")) == NULL) 
            fprintf(stderr,"Can't open %s\n",argv[i]);
       else
       {
           if(setvbuf(fs,NULL,_IOFBF,BULSIZE) != 0)
           {
               fputs("Can't create input buffer\n",stderr);             
               fclose(fs);
               continue;
           }
           addpend(fs,fa);
           if(ferror(fs) != 0)
           {
               fprintf(stderr,"Error in reading file %s \n", argv[i]);
           }       
           if(ferror(fa) != 0)
           {
               fprintf(stderr,"Error in writing file %s \n", argv[1]);
           }
           fclose(fs);
       }
    }
    fclose(fa);

    return 0;
}

void addpend(FILE *scurce, FILE *dest)
{
    size_t bytes;
    static char temp[BULSIZE];

    while((bytes = fread(temp,sizeof(char),BULSIZE,scurce)) >0)
    {
        fwrite(temp,sizeof(char),bytes,dest);
    }
}
