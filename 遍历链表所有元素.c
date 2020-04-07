#include <stdio.h>
#include <stdlib.h>
void write(struct SNode *p)
{
    while(p!=NULL)
    {
        printf("%i\n",p->num);
        p=p->next;          
    }
} 
main()
{
    system("pause");
}
