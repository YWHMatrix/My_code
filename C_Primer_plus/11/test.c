#include <stdio.h>
#include <ctype.h>

#define seiz 10

void get_str(char *,char *);

int main(int agrc,char *agrv [] )
{
    char scan[seiz];

    int i=0;
    while(i!=9)
    {
        gets(scan);
        puts(scan);
    }

    return 0;
}


