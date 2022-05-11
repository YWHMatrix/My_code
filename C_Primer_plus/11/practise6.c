#include <stdio.h>

int is_within(char ,char *);
int main()
{
    const int size = 21;
    char str[size];
    char ch;
    while(1)
    {
        puts("请输入字符串:");
        gets(str);
    //    fgets(str1,ENL,stdin);
        if(str[0] == '0')
            break;
 
        puts("请输入你要查找的字符:");
        scanf("%c",&ch);
        getchar();
        
        
        if(is_within(ch,str))
            printf("字符串中有%c字符\n",ch);
        else
            printf("字符串中没有%c字符\n",ch);
    }

    return 0;
}

int is_within(char ch,char *str)
{
    int i = 0;
    int r = 0;
    while(str[i] != '\0')
    {
        if(str[i] == ch)
        {
            r = 1;
        }
        i++;
    }
    
    return r;

}
