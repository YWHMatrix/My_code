#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define LEN 50

int main(int argc, char *argv[])
{
    int ch;
    int i = 0;
    FILE *fp;
    char filename[LEN];

    printf("Please enter a filename: ");
    scanf("%49s", filename);

    if ((fp = fopen(filename, "r+")) == NULL)
    {
        printf("Can't open %s\n", filename);
        exit(EXIT_FAILURE);
    }
    while((ch = getc(fp)) != EOF)
    {
        fseek(fp,-1L,SEEK_CUR); // 文件指针退一位
        putc(toupper(ch),fp);
    }
       fclose(fp);

    return 0;
}

