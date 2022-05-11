#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char trans[11] = " .':~*=&%#";

int main(int argc , char *argv[])
{
    FILE *fp ,*dp;
    int ch;
    int n;
    char ch_str[20][31];

    if(argc < 2)
    {
        printf("Usage :%s filename\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp = fopen(argv[1],"r")) == NULL)
    {
        printf("Can't open %s file\n", argv[1]);
        exit(1);
    }
    if((dp = fopen(argv[2],"w")) == NULL)
    {
        printf("Can't open %s file\n", argv[2]);
        exit(2);
    }

    printf("请输入你读取的行数\n");
    scanf("%d", &n);
    int num_s[n][30];
    for(int  i = 0;i < n;i++ )
    {
        for(int j = 0;j < 30; )
        {
            ch = getc(fp);
            if(!isspace(ch))
            {
                num_s[i][j] = ch;
                j++;
            }
        }
    }
    /*for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 30; j++)
            printf("%c",num[i][j]);
        printf("\n");
    }
    转换字符*/
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 31;j++)
        {
            if(j == 30)
            {
                ch_str[i][j] = '\0';
                break;
            }
            switch (num_s[i][j])
            {
            case 48:
                ch_str[i][j] = trans[0];
                break;
            case 49:
                ch_str[i][j] = trans[1];
                break;
            case 50:
                ch_str[i][j] = trans[2];
                break;
            case 51:
                ch_str[i][j] = trans[3];
                break;
            case 52:
                ch_str[i][j] = trans[4];
                break;
            case 53:
                ch_str[i][j] = trans[5];
                break;
            case 54:
                ch_str[i][j] = trans[6];
                break;
            case 55:
                ch_str[i][j] = trans[7];
                break;
            case 56:
                ch_str[i][j] = trans[8];
                break;
            case 57:
                ch_str[i][j] = trans[9];
                break;
            default:
                printf("访问数组失败!\n");
                break;
  
            }
        }
    }

    for(int i =0; i < n ; i++)
    {
        fprintf(dp,"%s",ch_str[i]);
        fprintf(dp,"%c",'\n');
    }

    if(fclose(fp) != 0)
    {
        printf("file close failed\n");
    }
    
   return 0;
}

