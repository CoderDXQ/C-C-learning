#include <stdio.h>
#include <stdlib.h>
struct SNode *Insert_node(struct SNode *head,int num)
{
    struct SNode *p,*p1,*p2;
    
    p=malloc(sizeof(struct SNode));
    p->num=num;//p是待插入的节点 
    
    if(head==NULL||p->num<=head->num)
    {
        p->num=head;
        return p;
    }
    p2=p1=head;
    while(p->num>p2->num&&p2->next)
    {
        p1=p2;
        p2=p2->next;//指针运动 
    }
    if(p2->next==NULL)
    {
        p2->next=p;
        p->next=NULL; 
    }
    else
    {
        p->next=p2;
        p1->next=p;
    }
    return head;
} 
main()
{
    system("pause");
}
