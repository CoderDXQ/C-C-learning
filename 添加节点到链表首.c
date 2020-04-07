#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct SNode
{
    int num;
    struct SNode *next;
};  
main()
{
    struct SNode *p,*head=NULL;
    do
    {
         p=malloc(sizeof(struct SNode));
         scanf("%d",&p->num);
         p->next=head;//NULL在最开始 
         head=p;
    }
    while(p->num!=-1);
    system("pause");
}
