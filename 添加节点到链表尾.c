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
    struct SNode *p,*t,*head=NULL,*tail=NULL;//�������ǽṹ�����͵� 
    void write(struct SNode *t);
    do
    {
        p=malloc(sizeof(struct SNode));
        printf("%d\n",p);
        scanf("%d",&p->num);//scanf����ʹ�õ��ǵ�ַ 
        if(head==NULL)
        {
            head=p;//��Ҫ���������һ�� 
            tail=p;
            
        }
        else
        {
            tail->next=p;//��һ����β��������һ���ĵ�ַ�� 
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
    struct SNode *p,*head=NULL,*tail=NULL;//�������ǽṹ�����͵� 
    void write(struct SNode *t);//�����еĺ������� 
    do
    {
        p=malloc(sizeof(struct SNode));
        printf("%d\n",p);
        scanf("%d",&p->num);//scanf����ʹ�õ��ǵ�ַ 
        if(head==NULL)
        {
            head=p;//��Ҫ���������һ�� 
            tail=p;
            
        }
        else
        {
            tail->next=p;//��һ����β��������һ���ĵ�ַ�� 
            tail=tail->next;
        }
    }
    while(p->num!=-1);
    
    p->next=NULL;//�����еĽ�β���� 
    
    printf("%d\n",p->num);
    
    write(head);//����ַ 
    system("pause");
}

