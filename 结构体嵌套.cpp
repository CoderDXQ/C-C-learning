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
      struct studentEx st[5],t;
      struct studentEx *p=st;
      int i,j;
      for (i=0;i<5;i++)
      {
          scanf("%d %s %d %d %f %s %s",&st[i].base.num,st[i].base.name,&st[i].base.sex,&st[i].base.age,&st[i].base.score,st[i].addr,st[i].phone);
      }
      for(i=0;i<4;i++)
          for (j=0;j<4-i;j++)
              if (st[j].base.score<st[j+1].base.score)
              {
                  t=st[j];
                  st[j]=st[j+1];
                  st[j+1]=t;                          
              }
      for(i=0;i<5;i++)
          printf("%d,%s,%s,%.1f,%s,%s\n",
              st[i].base.num,
              st[i].base.name,//(st+i)->base.name,
              st[i].base.sex?"男":"女",//(p+i)->base.sex?"男":"女",
              st[i].base.score,//(*(p+i)).base.score,
              st[i].addr,// p[i].addr,
              st[i].phone);//(*(st+i)).phone);  
              //利用指针输出结构体的各种方法 
      system("pause");
}
