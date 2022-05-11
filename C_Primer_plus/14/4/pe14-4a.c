#include <stdio.h>
#include <string.h>

#define MAX 10


struct names  {
    char name[MAX];     // 名
    char surname[MAX]; // 姓
    char midname[MAX]; // 中间名
};
struct insurance{
    int number;
    struct names people;
};

void show(struct insurance *p);

int main()
{

    struct insurance folk[5] = {
        {302039823,{"Flossie","Dribble","Mak"}},
        {302039824,{"Ace","LI"}},
        {302039825,{"TOME","Xun","Tom"}},
        {302039826,{"Rvren","Meng","San"}},
        {302039823,{"Sou","Ya"}}
    };
    show(folk);
    return 0;
}

void show(struct insurance *p)
{

    for(int i = 0; i < 5; i++)
    {
        printf("%s,%s ",p[i].people.surname,p[i].people.name);
        if(p[i].people.midname[0] !='\0')
        {
            printf("%c.",p[i].people.midname[0]);
        }
        printf("——%d\n",p[i].number);
    }

}
