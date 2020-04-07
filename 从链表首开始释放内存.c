#include <stdio.h>
#include <stdlib.h>
void freelink(struct SNode *head)
{
    struct SNode *p;
    while(head)
    {
        p=head;
        head=head->next;
        free(p); 
    }    
}
main()
{
    



    system("pause");
}
