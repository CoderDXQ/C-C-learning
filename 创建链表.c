#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
    int num;
    char name[20];
    double score;
    struct student *next;//必须要有的一部分，将链表连接起来 
}; 
void shuchu(struct student *p);//必须要在主函数之外有声明 

void shuchu(struct student *p)//此处不能加分号 
{
     printf("%d,%s,%.1f\n",p->num,p->name,p->score);//不需要加取值符 
        
}

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
    c->next=NULL;//结尾必须是NULL 
    
    
    shuchu(a);
    shuchu(b);
    shuchu(c);
 //内存释放要放在输出后面   
    free(head);
    free(a);
    free(b);
    

    system("pause");
}
