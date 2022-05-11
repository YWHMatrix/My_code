#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

const char trans[11] = " .':~*=&%#";
void eliminate(int n[20][30]);

int main(int argc , char *argv[])
{
    FILE *fp ,*dp;
    int ch;
    int num[20][30];
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
    for(int  i = 0;i < 20;i++ )
    {
        for(int j = 0;j < 30; )
        {
            ch = getc(fp);
            if(!isspace(ch))
            {
                num[i][j] = ch;
                j++;
            }
        }
    }
    eliminate(num);
    
    /*for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 30; j++)
            printf("%c",num[i][j]);
        printf("\n");
    }
    转换字符*/
    for(int i = 0; i < 20; i++)
    {
        for(int j = 0; j < 31;j++)
        {
            if(j == 30)
            {
                ch_str[i][j] = '\0';
                break;
            }
 /*            第一版
             switch (num[i][j])

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
  
            }*/
            // 改进版
             ch_str[i][j] = trans[num[i][j] - 48]; 
            
        }
    }

    for(int i =0; i < 20 ; i++)
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

void eliminate(int n[20][30])
{
    for(int x = 0;x < 20;x++)
    {
        for(int y = 0;y < 30;y++)
        {
            if(x == 0)
            {
                if(y == 0) // 左上定点
                {
                    if((n[x][y] - n[x][y+1]) > 1 && (n[x][y] - n[x+1][y]) > 1)
                    {
                        n[x][y] = (n[x][y+1] + n[x+1][y]) / 2.0 + 0.5; 
                        continue;
                    }
                }
                else if(y == 29)//右上定点
                {
                    if((n[x][y] - n[x][y-1]) > 1 && (n[x][y] - n[x+1][y]) > 1)
                    {
                        n[x][y] = (n[x][y-1] + n[x+1][y]) / 2.0 + 0.5; 
                        continue;
                    }
                }
                else//上边界中间部分
                {
                    if((n[x][y] - n[x][y-1]) > 1 && (n[x][y] - n[x][y-1]) > 1 && (n[x][y] - n[x+1][y]) > 1)
                    {
                        n[x][y] = (n[x][y-1] + n[x][y+1] + n[x+1][y]) / 3.0 + 0.5;
                        continue;
                    }
                }
            }
            else if(x == 19)
            {
                if(y == 0)//左下定点
                {
                    if((n[x][y] - n[x][y+1]) > 1 && (n[x][y] - n[x-1][y]) > 1)
                    {
                        n[x][y] = (n[x][y+1] + n[x-1][y]) / 2.0 + 0.5; 
                        continue;
                    }
                }
                else if(y == 29)
                {
                    if((n[x][y] - n[x][y-1]) > 1 && (n[x][y] - n[x-1][y]) > 1)
                    {
                        n[x][y] = (n[x][y-1] + n[x-1][y]) / 2.0 + 0.5; 
                        continue;
                    }
                }
                else//下边界中间部分
                {
                    if((n[x][y] - n[x][y-1]) > 1 && (n[x][y] - n[x][y-1]) > 1 && (n[x][y] - n[x+1][y]) > 1)
                    {
                        n[x][y] = (n[x][y-1] + n[x][y+1] + n[x-1][y]) / 3.0 + 0.5;
                        continue;
                    }
                }
            }
            if(y == 0)//左边中间边界
            {
                if((n[x][y] - n[x-1][y]) > 1 && (n[x][y] - n[x+1][y]) > 1 && (n[x][y] - n[x][y+1]))
                {
                    n[x][y] = (n[x][y+1] + n[x+1][y] +n[x-1][y]) / 3.0 + 0.5;
                    continue;
                }
            }
            if(y == 29)//右边中间边界
            {
                if((n[x][y] - n[x-1][y]) > 1 && (n[x][y] - n[x+1][y]) > 1 && (n[x][y] - n[x][y-1]))
                {
                    n[x][y] = (n[x][y-1] + n[x+1][y] +n[x-1][y]) / 3.0 + 0.5;
                    continue;
                }
                
            }
            //处理剩下的
            if((n[x][y] - n[x-1][y]) > 1 && (n[x][y] - n[x+1][y]) > 1 && 
               (n[x][y] - n[x][y-1]) > 1 && (n[x][y] - n[x][y+1]))
                n[x][y] = (n[x-1][y] + n[x+1][y] + n[x][y-1] + n[x][y+1]) / 4.0 + 0.5;
        }
    }

}
