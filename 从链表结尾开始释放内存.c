#include <stdio.h>
#include <stdlib.h>
void freelink(struct SNode **p)
{
    if((*p)->next==NULL)
    {
        free(*p);
        *p=NULL;
    }  
    else
    {
        freelink(&(*p)->next);
        free(*p);
        *p=NULL; 
    }
} 
main()
{




    system("pause");
}
