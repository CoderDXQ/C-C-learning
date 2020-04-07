#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct SNode
{
  int num;
  struct SNode *next;     
};
main()
{
    struct SNode *p,*head=NULL,*tail=NULL;//变量都是结构体类型的 
    do
    {
        p=malloc(sizeof(struct SNode));
        scanf("%d",&p->num);//scanf函数使用的是地址 
        if(head==NULL)
        {
            head=p;//主要用来处理第一个 
            tail=p;
        }
        else
        {
            tail->next=p;//后一个的尾巴连到上一个的地址上 
            tail=tail->next;
        }
    }
    while(p->num!=-1);
    system("pause");
}
