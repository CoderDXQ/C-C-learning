#include <stdio.h>
#include <stdlib.h>
struct SNode *delete_node(struct SNode *head,int num)
{
    struct SNode *p1,*p2;
    if(!head)
        return NULL;
    if(head->num==num)//处理删除第一个的情况 
    {
        p1=head;
        head=head->next;
        free(p1);      
    }
    else
    {
        p2=p1=head;
        while(p2->num!=num&&p2->next)
        {
            p1=p2;
            p2=p2->next;
        }
        if(p2->num=num)
        {
            p1->next=p2->next;//删除目标 
            free(p2);
        }
    }
    return head;
}
main()
{




    system("pause");
}
