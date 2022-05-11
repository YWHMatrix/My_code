#include <stdio.h>

#define seiz 100

void get_str(char *,int n);

int main(int agrc,char *agrv [] )
{
    char scan[seiz];
    int n;
    puts("请输入你要输入多少个字符:");
    scanf("%d",&n);
    getchar();
    get_str(scan,n);
    puts(scan);

    printf("\n");
    return 0;
}

void get_str(char *scan,int n)
{
    for(int i=0; i<n-1; i++)
    {
        scan[i] = getchar();
    }
        scan[n] = '\0';
}

