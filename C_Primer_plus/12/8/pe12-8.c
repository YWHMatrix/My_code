#include <stdio.h>
#include <stdlib.h>

int *make_array(int elem, int val);
void show_array(const int ar [], int n);

int main()
{
    int *pa;
    int size;
    int value;
    printf("Enter the number of elements:  ");
    while(scanf("%d", &size) == 1 && size > 0)
    {
        printf("Enter the initialization value: ");
        scanf("%d", &value);
        pa = make_array(size, value);
        if(pa)
        {
            show_array(pa, size);
            free(pa);
        }
        printf("Enter the number of elements(<1 to quit ): ");
    }
    printf("Done.\n");

    return 0;
}

int *make_array(int  e, int v)
{
    int *pt;
    
    pt =(int *) malloc( e * sizeof(int) );
    if(pt == NULL)
    {
        printf("Memory allocation failed . Goodbye.");
        exit(EXIT_FAILURE);
    }

    for(int i = 0; i < e; i++)
    {
        pt[i] = v;
    }
    
    return pt;
    
}

void show_array(const int ar [] , int n)
{
    for(int i = 0; i < n; i++)
    {
        printf("%-3d" , ar[i]);
        if((i+1) % 8 == 0)
            printf("\n");
    }
    printf("\n");

}
