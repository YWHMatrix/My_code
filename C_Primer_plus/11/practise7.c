#include <stdio.h>
#include <string.h>
#define ENL 81

void mystrncpy(char *,char *,int);

int main(int agrc,char *agrv[]) 
{
    char str1[ENL];
    char str2[ENL]; 
    int n;
    while(1)
    {
        puts("请输入字符串str2:");
        fgets(str2,ENL,stdin);
        puts("请输入你要拷贝字符的个数:");
        scanf("%d",&n);
        getchar();
        
        if(n == 0)
            break;
        mystrncpy(str1,str2,n);
        puts(str1);
                
    }
    return 0;
}

void mystrncpy(char *s1,char *s2,int n)
{
    int i = 0;
    for(;i<n;i++)
    {
        s1[i] =s2[i];
    }

    if(n < (int) strlen(s2)) 
    {
        s1[i++] = '\0';
    }
}
