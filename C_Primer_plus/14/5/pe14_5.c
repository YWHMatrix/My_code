#include <stdio.h>
#include <string.h>

#define MAX 10
#define CSIZE 4

struct name{
    char names[MAX];
    char surname[MAX];
};

struct student {
    struct name student_s;
    float grade[3];
    float average;
};

char *s_gets(char *,int n);

int main()
{
    struct student students[CSIZE];
    float tatlo = 0;
    for(int i = 0; i < CSIZE; i++)
    {
        printf("请输入姓名和分数:\n");
        scanf("%10s %10s",students[i].student_s.surname , students[i].student_s.names);
        scanf("%f %f %f",&students[i].grade[0],&students[i].grade[1],&students[i].grade[2]);
    }
    for(int i = 0; i < CSIZE ; i++)
    {
        students[i].average = ((students[i].grade[0]+students[i].grade[1]+students[i].grade[2]) / 3.0);
    }
    printf("每个人的平均成绩\n");
    for(int i = 0; i < CSIZE ; i++)
    {
        printf("%.2f\n",students[i].average);
    }
    printf("全班的平均成绩\n");
    for(int i = 0; i < CSIZE ; i++)
    {
        tatlo += students[i].average;
    }
    tatlo = tatlo / 4.0;
    printf("%.2f\n", tatlo);
    return 0;
}

