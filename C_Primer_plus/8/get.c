#include <stdio.h>

int main(int n,char **argv)
{
    int ch;
    while((ch=getchar())!='\n')
    {
        putchar(ch);
    }
    return 0;
}

