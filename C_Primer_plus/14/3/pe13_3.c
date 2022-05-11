#include <stdio.h>
#include <string.h>

#define MAXTITL 41
#define MAXAUTL 41
#define MAXBKS 16

char *s_gets(char *st,int n);

struct book {
    char title[MAXTITL]; // 书名
    char author[MAXAUTL]; //作者名
    float value;          //价格
};

int main()
{
    struct book library[MAXBKS];
    int count = 0;
    char ch[MAXBKS];
    char  temp;
    int b[MAXBKS];
    int t;
    float tv;
    float v[MAXBKS];

    while(count <MAXBKS && s_gets(library[count].title,MAXTITL) != NULL 
          && library[count].title[0] != '\0')
    {
        printf("请输入作者\n");
        s_gets(library[count].author,MAXAUTL);
        printf("请输入书本价格\n");
        scanf("%f",&library[count++].value);
        while(getchar() != '\n')    
            continue;
        if(count < MAXBKS)
            printf("Enter the next titlie.\n");
    }
    
    printf("按输入顺序输出:\n");
    if(count > 0)
    {
        for(int i =0 ; i < count; i++)
        {
            printf("书名：%s  ",library[i].title);
            printf("作者：%s  ",library[i].author);
            printf("价格：%f\n",library[i].value);
        }
    }
    printf("按书本首字母输出\n");
    if(count > 0)
    {
        for(int i = 0; i < count; i++)
        {
            ch[i] = library[i].title[0];
            b[i] = i; //用于标记
        }
        for(int i = 0; i < count - 1; i++)
            for(int j=0; j < count-1;j++)
            {
                if(ch[j] > ch[j+1])
                {
                    temp = ch[j];     
                    ch[j] = ch[j+1]; 
                    ch[j+1] = temp;
                    t = b[j];
                    b[j]  = b[j+1];
                    b[j+1] = t;
                }
            }
        for(int i = 0; i < count; i++)
        {
            printf("书名：%s  ",library[b[i]].title);
            printf("作者：%s  ",library[b[i]].author);
            printf("价格：%f\n",library[b[i]].value);
        }
    }
    printf("按价格升序输出:\n");
    if(count > 0)
    {
        for(int i = 0; i < count; i++)
        {
            v[i] = library[i].value;
            b[i] = i;
        }
        
        for(int i = 0; i < count - 1; i++)
            for(int j=0; j < count-1;j++)
            {
                if(v[j] < v[j+1])
                {
                    tv = v[j];
                    v[j] = v[j+1];
                    v[j+1] = tv;
                    t = b[j];
                    b[j]  = b[j+1];
                    b[j+1] = t;
                }
            }
        for(int i = 0; i < count; i++)
        {
            printf("书名：%s  ",library[b[i]].title);
            printf("作者：%s  ",library[b[i]].author);
            printf("价格：%f\n",library[b[i]].value);
        }
    }

    return 0;
}

char *s_gets(char *st,int n)
{
    char *ret_val;
    char *find;
    ret_val = fgets(st,n,stdin);
    if(ret_val)
    {
        find = strchr(st,'\n');
            if(find)
                *find = '\0';
            else
                while(getchar()!='\n')
                    continue;
    }
    return ret_val;

}
