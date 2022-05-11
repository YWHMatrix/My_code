#ifndef _DliskList_H_

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct node
{
    ElemType data;
    
    struct node *next,    *prior;
    
};

typedef struct node *DliskList;

#endif //  _DliskList_H_