#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define LEN 256

void word(int n);

int main()
{
    int num;

    printf("How many words do you wish to enter? ");
    scanf("%d", &num);
    printf("Enter %d words now:\n", num);
    word(num);

    return 0;
}

void word(int n)
{
    char **pt;
    char tmep[LEN];
    int len;

    if((pt = (char **)malloc(n * sizeof(char *))) != NULL)
    {
        for(int i = 0; i < n; i++)
        {
            scanf("%255s",tmep);
            len = strlen(tmep) + 1;
            pt[i] = (char *)malloc(len * sizeof(char));
            if(pt[i] == NULL)
            {
                printf("内存分配失败!\n");
                exit(EXIT_FAILURE);
            }
            strcpy(pt[i],tmep);
        }
    }
    else
    {
        printf("内存分配失败!\n");
        exit(EXIT_FAILURE);
    }

    printf("Here are your words: \n");
    for(int i = 0; i < n; i++)
    {
        puts(pt[i]);
        free(pt[i]);
        pt[i] = NULL;
    }

    free(pt);
    pt = NULL;
}

