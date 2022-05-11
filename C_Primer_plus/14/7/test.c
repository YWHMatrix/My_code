#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE *fp;
    char ch[]={"aaaa"};
    /* char bull[1024] = {0}; */
    int j = 0;
    fp = fopen("b.dat","wb");
    if(fp == NULL)
    {
        printf("文件打开失败\n");
        exit(1);
    }
    for(int i = 0; i < 6; i++)
    {
        fwrite(ch,sizeof(ch),1,fp);
    }
    /* while(getc(fp) && !feof(fp)) */
    /* { */
    /*     fseek(fp,-1L,SEEK_CUR); */
    /*     fread(ch,5,1,fp); */ 
    /*     printf("%s",ch); */
    /*     j++; */
    /* } */
    fclose(fp);
    return 0;
}
