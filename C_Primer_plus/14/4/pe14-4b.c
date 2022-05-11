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

void show(struct insurance p);

int main()
{

    struct insurance folk[5] = {
        {302039823,{"Flossie","Dribble","Mak"}},
        {302039824,{"Ace","LI"}},
        {302039825,{"TOME","Xun","Tom"}},
        {302039826,{"Rvren","Meng","San"}},
        {302039823,{"Sou","Ya"}}
    };
    for(int i = 0; i < 5 ; i++)
    {
        show(folk[i]);
    }
    return 0;
}

void show(struct insurance p)
{

        printf("%s,%s ",p.people.surname,p.people.name);
        if(p.people.midname[0] !='\0')
        {
            printf("%c.",p.people.midname[0]);
        }
        printf("——%d\n",p.number);

}
