#include <stdio.h>
#include <stdlib.h>
struct student
{
       int num;
       char name[20];
       int sex;
       int age;
       float score;
};
struct studentEx
{
       struct student base;
       char addr[40];
       char phone[20];
};
main()
{
      struct studentEx st1,st2;
      struct studentEx *p=&st1;
      scanf("%d %s %d %d %f %s %s",&p->base.num,&p->base.name,&p->base.sex,&p->base.age,&p->base.score,p->addr,p->phone);
      p=&st2;
      scanf("%d %s %d %d %f %s %s",&p->base.num,&p->base.name,&p->base.sex,&p->base.age,&p->base.score,p->addr,p->phone);
      if (st1.base.score>st2.base.score)
          p=&st1;      
      else 
          p=&st2;
      printf("学号： %d,姓名：%s\n     性别: %s",(*p).base.num,(*p).base.name,(*p).base.sex?"男":"女"); 
      system("pause");
}
