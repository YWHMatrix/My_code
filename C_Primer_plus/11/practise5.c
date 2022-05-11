#include <stdio.h>
#define ENL 81

char *chr(char *,char );
int main(int agrc,char *agrv[]) 
{
    char str1[ENL];
    char ch;
    while(1)
    {
        puts("请输入字符串:");
        gets(str1);
    //    fgets(str1,ENL,stdin);
        puts("请输入你要查找的字符:");
        scanf("%c",&ch);
        getchar();
        
        if(ch == '0')
            break;

        if(chr(str1,ch) == NULL)
        {
            puts("字符串中没有你要找的字符");
        }
        else
        {
            puts(chr(str1,ch));
        }
        
    }
    return 0;
}

char *chr(char *str1,char ch)
{
    int i=0;
    char *pt;
    while(str1[i] !='\0')       
    {
        if(str1[i] == ch)
        {
            pt=(str1+i);
            break;
        }
        i++;
        pt=NULL;
    }
    
    return pt;
}
