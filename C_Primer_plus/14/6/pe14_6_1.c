//使用动态分配内存版，第一个版
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 29
#define LEN 50
#define len 10

struct player {
    int p_number;
    char p_name[len];
    char p_surname[len];
    int play;
    int hit;
    int go;
    int rbi;
    float rate;
};

int main(int argc,char *argv[])
{
    int number [SIZE] = {0}; // 球号索引
    FILE *fp;
    int date[SIZE][4] = {0}; //存放最后4组数据
    char *names[SIZE]; //临时存放队员名
    char *surnames[SIZE];//临时存放队员的姓
    char temp[LEN];    //临时存放每一行的球员数据
    struct player people[SIZE];

    if(argc < 2)
    {
        printf("Useag: %s file\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    if((fp = fopen("test.txt", "r")) == NULL)
    {
        printf("Can't open %s file\n",argv[1]);
        exit(1);
    }
    while(fgets(temp,LEN,fp) != NULL) //当文件到达结尾返回NULL
    {
        char *find;
        char str[2] = " ";
        char *token;
        find = strchr(temp,'\n');
        if(!find) //没找到换行符，，文件数据超过了处理的大小
        {
            printf("文件数据不对\n");
            exit(2);
        }
        
       token = strtok(temp,str);
        int num = 0;
        int count = 0;
        for(int j = 1; j <= 7 ; j++ ) //一行有七个参数，而且用空格分开
        {   
            int i = 0;
            int tp = 0;
            switch (j)
            {
            case 1:
                while(token[i] != '\0') // 球员号：0~28
                {
                    num = num*10+(token[i] - 48);
                    i++;
                }
                if(number[num] == 0) //如果该球员是首次出现，标记一下
                {
                    count = 1;
                    number[num] = num ;
                }
                token = strtok(NULL,str);
                break;
            case 2:
               if(count == 1)
               {
                   names[num] = (char *)malloc(10 * sizeof(char));
                   if(names[num] == NULL)
                   {
                       printf("内存分配失败");
                       exit(EXIT_FAILURE);
                   }
                   strcpy(names[num],token);
               }
                token = strtok(NULL,str);
                break;
            case 3:
               if(count == 1)
               {
                   count = 0;
                   surnames[num] = (char *)malloc(10 * sizeof(char));
                   if(surnames[num] == NULL)
                   {
                       printf("内存分配失败");
                       exit(EXIT_FAILURE);
                   }
                   strcpy(token,surnames[num]);
               }
                token = strtok(NULL,str);
                break;
            case 4: //上场数
                while(token[i] != 0)
                {
                    tp = tp*10+(token[i] - 48);
                    i++;
                }
                date[num][0] += tp;
                token = strtok(NULL,str);
                break;
            case 5://击中数
                while(token[i] != 0)
                {
                    tp = tp*10+(token[i] - 48);
                    i++;
                }
                date[num][1] += tp;
                token = strtok(NULL,str);
                break;
            case 6://走垒数
                {
                    tp = tp*10+(token[i] - 48);
                    i++;
                }
                date[num][2] += tp;
                token = strtok(NULL,str);
                break;
            case 7://打点数
                while(token[i] != '\n')
                {
                    tp = tp*10+(token[i] - 48);
                    i++;
                }
                date[num][3] += tp;
                token = strtok(NULL,str);
                break;
            }
        }
    }
    for(int k = 0; k < SIZE ; k++)
    {
        people[k].p_number = number[k];
        strcpy(people[k].p_name,names[k]);
        strcpy(people[k].p_surname,surnames[k]);
        people[k].play = date[k][0];
        people[k].hit  = date[k][1];
        people[k].go   = date[k][2];
        people[k].rbi  = date[k][3];
        people[k].rate =(float)date[k][2]/ (float)date[k][0] ;
    }
    for(int k = 0; k < SIZE ; k++)
    {
        printf("%d  ",people[k].p_number);
        printf("%s %s ",people[k].p_name,people[k].p_surname);
        printf("%d %d %d %d ",people[k].play,people[k].hit,people[k].go,people[k].rbi);
        printf("%.2f\n",people[k].rate);
    }
    for(int k =0 ; k < SIZE ; k++)
    {
        free(names[k]);
        free(surnames[k]);
    }
    return 0;
}

