#include <stdio.h>
#include <ctype.h>

#define seiz 10

void get_str(char *,char *);

int main(int agrc,char *agrv [] )
{
    char scan[seiz];
    char input[seiz];
    puts("请输入一行");
    fgets(scan,seiz,stdin);
    /* gets(scan); */
    get_str(input,scan);
    puts(input);

    return 0;
}

void get_str(char *input,char *scan)
{
        int i=0;
        int j=0;

        while(isspace(scan[i]))
        {
            i++;
        }
       while(1) 
       {
           if(isspace(scan[i]))
               break;

           input[j] = scan[i];
           i++;
           j++;
       }
       input[j] = '\0';

}


