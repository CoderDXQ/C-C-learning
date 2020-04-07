#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student
{
    int num;
    char name[20];
    double score;
    struct student *next;
};  
void main()
{
    struct student *a,*b,*c,*head=NULL;
    a=malloc(sizeof(struct student));
    a->num=110011;
    strcpy(a->name,"张三");
    a->score=88.5;
    
    b=malloc(sizeof(struct student));
    b->num=110012;
    strcpy(b->name,"李四");
    b->score=90.2;
    
    c=malloc(sizeof(struct student));
    c->num=110013;
    strcpy(c->name,"王五");
    c->score=77.0;
    
    head=a;
    a->next=b;
    b->next=c;
    c->next=NULL;
    free(a);
    free(b);
    free(c);
    



    system("pause");
}
