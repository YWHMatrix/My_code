#include <stdio.h>
#include <stdlib.h>


int main()
{
    FILE *fp;
    char name[31];
    long num;
    char out[100];

    printf("Please enter a file name.\n");
    scanf("%30s", name);
    if((fp = fopen(name,"r")) == NULL)
    {
        printf("Can't open %s file.\n", name);
        exit(EXIT_FAILURE);
    }
    printf("请输入你要文件哪里开始打印内容\n");
    while(scanf("%ld",&num) != 0 && num >= 0)
    {   
        num--;
        fseek(fp,num,SEEK_SET);
        fgets(out,100,fp);
        fputs(out,stdout);
    }
    fclose(fp);
    return 0;
}

