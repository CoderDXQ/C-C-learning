/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct SNode
{
  int num;
  struct SNode *next;     
};
   
main()
{
    struct SNode *p,*t,*head=NULL,*tail=NULL;//变量都是结构体类型的 
    void write(struct SNode *t);
    do
    {
        p=malloc(sizeof(struct SNode));
        printf("%d\n",p);
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
    
    p->next=NULL;
    
    printf("%d\n",p->num);
    
   while(head!=NULL)
    {
        printf("%d\n",head->num);
        head=head->next;          
    }
    //write(p);
    system("pause");
}


*/


    
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct SNode
{
  int num;
  struct SNode *next;     
};

void write(struct SNode *t)
{
    while(t!=NULL)
    {
        printf("%d\n",t->num);
        t=t->next;          
    }
}; 
    
main()
{
    struct SNode *p,*head=NULL,*tail=NULL;//变量都是结构体类型的 
    void write(struct SNode *t);//必须有的函数声明 
    do
    {
        p=malloc(sizeof(struct SNode));
        printf("%d\n",p);
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
    
    p->next=NULL;//必须有的结尾工作 
    
    printf("%d\n",p->num);
    
    write(head);//传地址 
    system("pause");
}

