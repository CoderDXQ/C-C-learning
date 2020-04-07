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
typedef struct student ST; 
main()
{
      ST xs1;
      scanf("%d%s%d%d%f",&xs1.num,xs1.name,&xs1.sex,&xs1.age,&xs1.score);
      printf("%d,%s,%d,%d,%.2f",xs1.num,xs1.name,xs1.sex,xs1.age,xs1.score);
      system("pause");
}
