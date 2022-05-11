#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>

#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS  10

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value ;
};

struct books {
    struct book b;
    bool d;    //用于是否要删
    bool null; // 用于标记是否有数据存储
};

char * s_gets(char * ,int);
void show_book();
int  g_first(char *);
void EmptyLine();
void upda();

struct books library[MAXBKS];

FILE *fpbooks;
int main ()
{
     char temp[MAXTITL];
     if((fpbooks = fopen("book.dat","r+b")) == NULL)
     {
         fputs("Can't open book.dat file\n", stderr);
         exit(1);
     }
     show_book();
     if((fpbooks = fopen("book.dat","wb+")) == NULL)
     {
         fputs("Can't open book.dat file\n", stderr);
         exit(1);
     }
     puts("你是否要删除或者修改数据(输入 y or n):");
     if(g_first("yn") == 'y')
     {

         printf("请输入你要删除或者修改的操作(d or r)\n");
         if(g_first("rd") == 'd')
         {
             puts("请输入你要删除的书本");
             s_gets(temp,MAXTITL);
             int i = 0;
             for(i =0 ; i < MAXBKS ; i++)
             {
                 if(!strcmp(temp,library[i].b.title)) //找到要删除的书,并标记上
                 {
                     library[i].d = true;
                     break;
                 }
             }
             if((i+1)==MAXBKS)
             {
                 puts("没有找到你要删除的书");
                 puts("程序退出！");
             }
         }
         else
         {
             puts("请输入你要修改的书");
             s_gets(temp,MAXAUTL);
             int i = 0;
             for(i =0 ; i < MAXBKS ; i++)
             {
                 if(!strcmp(temp,library[i].b.title)) //找到要修改的书
                 {
                     printf("是否要修改书名(y or n):");
                     if(g_first("yn") == 'y')
                     {
                         puts("输入要修改的书名:");
                         s_gets(library[i].b.title,MAXAUTL);
                     }
                     printf("是否修改作者(y or n):");
                     if(g_first("yn") == 'y')
                     {
                         puts("输入要修改的作者:");
                         s_gets(library[i].b.author,MAXAUTL);
                     }
                     printf("是否修改价格:");
                     if(g_first("yn") == 'y')
                     {
                         puts("请输入要修改的价格:");
                         scanf("%f",&library[i].b.value);
                     }
                     break;
                 }
             }
             if(i == MAXBKS)
             {
                 puts("没有找到你要修改的书");
                 puts("程序退出！");
             }
         }
     }
     else
     {
         upda();
         puts("程序退出!");
         exit(3);
     }
     upda();
    return 0;
}
void show_book()
{
    int size = sizeof(struct book);
    int i = 0;
    rewind(fpbooks); // 定位到文件开始
    while(i < MAXBKS  && fread(&library[i].b,size,1,fpbooks) == 1)
    {
        library[i].null = true;
        puts("书名:");
        printf("%s\n",library[i].b.title);
        puts("作者:");
        printf("%s\n",library[i].b.author);
        puts("价格:");
        printf("%.2f\n",library[i].b.value);
        i++;
    }
    printf("\n");
    fclose(fpbooks);
}

int g_first(char * str)
{
    int ch;
    ch = tolower(getchar());
    while(strchr(str,ch) == NULL)
    {
        printf("数据错误，请从新输入\n");
        EmptyLine();
        ch = tolower(getchar());
    }
    EmptyLine();
    return ch;
}

void EmptyLine ()
{
    while(getchar() != '\n')
        continue;
}

char *s_gets(char * str ,int n)
{
    char *str_g;
    char *find;

    str_g = fgets(str,n,stdin);
    if(str_g)
    {
        find = strchr(str,'\n');
        if(find)
            *find = '\0';
        else
            EmptyLine();
    }
    return str_g;
}
void upda()
{
    rewind(fpbooks);
    int size = sizeof(struct book);
    for(int i = 0 ; i < MAXBKS ; i++)
    {
        if(library[i].d == true || library[i].null == false)
            continue;
        fwrite(&library[i].b,size,1,fpbooks);
    }
}
