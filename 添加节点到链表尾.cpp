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
    struct SNode *p,*head=NULL,*tail=NULL;//�������ǽṹ�����͵� 
    do
    {
        p=malloc(sizeof(struct SNode));
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
    system("pause");
}
