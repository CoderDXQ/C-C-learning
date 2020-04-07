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
      struct studentEx st[2];
      struct studentEx *p;
      int i; 
      for (i=0;i<2;i++)
      {
      scanf("%d %s %d %d %f %s %s",&st[i].base.num,&st[i].base.name,&st[i].base.sex,&st[i].base.age,&st[i].base.score,st[i].addr,st[i].phone);
      }
      
      if (st[1].base.score>st[2].base.score)
          i=1;     
      else 
          i=2;
      printf("学号： %d,姓名：%s\n     性别: %s",st[i].base.num,&st[i].base.name,&st[i].base.sex?"男":"女"); 
      system("pause");
}
