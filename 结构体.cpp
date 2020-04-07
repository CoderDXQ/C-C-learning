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
      scanf("%d %s %d %d %f %s %s",&st1.base.num,&st1.base.name,&st1.base.sex,&st1.base.age,&st1.base.score,st1.addr,st1.phone);
      scanf("%d %s %d %d %f %s %s",&st2.base.num,&st2.base.name,&st2.base.sex,&st2.base.age,&st2.base.score,st2.addr,st2.phone);
      if (st1.base.score>st2.base.score)
          printf("学号： %d,姓名： %s\n",st1.base.num,st1.base.name);      
      else 
          printf("学号： %d,姓名： %s\n",st2.base.num,st2 .base.name                                         ); 
      system("pause");
}
