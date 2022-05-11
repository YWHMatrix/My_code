#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 81

int main() 
{
    FILE *in , *out;
    int ch;
    int count = 0;
    char in_name[LEN];
    char out_name[LEN];
    printf("Please enter the compressed source file name:");
    scanf("%81s", in_name);
    if((in = fopen(in_name,"r")) == NULL)
    {
        printf("can't open %s \n", in_name);
        exit(1);
    }    
    strncpy(out_name,in_name,LEN-5); 
    out_name[LEN-5] = '\0';
    strcat(out_name,".red");
    if((out = fopen(out_name,"w")) == NULL)
    {
        printf("can't open %s \n", in_name);
        exit(1);
    }
    while((ch = getc(in)) != EOF)
    {
        if(count++ % 3 != 0)
        {
            putc(ch,out);
        }
    }
    fclose(in);
    fclose(out);

    return 0;
}

