#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 41

int main()
{
    FILE *fp;
    char words[MAX];
    /* char temp[MAX]; */
    int count = 0;
    int ch;

    if((fp = fopen("wordy","a+")) == NULL)
    {
        fprintf(stderr,"Can't open \"wordy\" file\n");
        exit(EXIT_FAILURE);
    }
    
    while((ch = getc(fp)) != EOF)
    {
        if(ch == '\n')
            count++;
    }
    rewind(fp);
    puts("请你输入你要输入的字符串，按#结束");
    while((fscanf(stdin,"%40s",words) ==1) && words[0] !='#')
    {
        fprintf(fp,"%-2d : %s\n",++count,words);
    }
    rewind(fp);
    while((fgets(words,MAX,fp)))
    {
        puts(words);
    }
    
    if(fclose(fp) != 0)
        fprintf(stderr,"Error closing file\n");
    return 0;
}

