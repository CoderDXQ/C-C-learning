#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int num;
    char name[20];
    double score;
    struct student *next;//����Ҫ�е�һ���֣��������������� 
}; 
void shuchu(struct student *p);//����Ҫ��������֮�������� 

void shuchu(struct student *p)//�˴����ܼӷֺ� 
{
     printf("%d,%s,%.1f\n",p->num,p->name,p->score);//����Ҫ��ȡֵ�� 
        
}

void main()
{
    struct student *a,*b,*c,*head=NULL;
    a=malloc(sizeof(struct student));
    a->num=110011;
    strcpy(a->name,"����");
    a->score=88.5;
    
    b=malloc(sizeof(struct student));
    b->num=110012;
    strcpy(b->name,"����");
    b->score=90.2;
    
    c=malloc(sizeof(struct student));
    c->num=110013;
    strcpy(c->name,"����");
    c->score=77.0;
    
    head=a;
    a->next=b;
    b->next=c;
    c->next=NULL;//��β������NULL 
    
    
    shuchu(a);
    shuchu(b);
    shuchu(c);
 //�ڴ��ͷ�Ҫ�����������   
    free(head);
    free(a);
    free(b);
    

    system("pause");
}
