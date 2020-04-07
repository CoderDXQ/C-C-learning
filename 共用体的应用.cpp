#include <stdio.h>
#include <stdlib.h>
struct BOY
{
       int Run;
       int Longjump;
       int Shot;
       };
struct GIRL
{
       int Skip;
       int Situps;
};
struct STUDENT
{
       int num;
       char name[16];
       int sex;
       union
       {
            struct GIRL girl;
            struct BOY boy;
            }score;
       };
main()
{
      struct STUDENT xs[3];
      int i;
      for(i=0;i<3;i++)
      {
           scanf("%d %s %d",&xs[i].num,xs[i].name,&xs[i].sex);
           if (xs[i].sex)
               scanf("%d %d %d",&xs[i].score.boy.Longjump,&xs[i].score.boy.Run,&xs[i].score.boy.Shot);
           else
               scanf("%d %d",&xs[i].score.girl.Situps,&xs[i].score.girl.Skip);           
                      }
      for(i=0;i<3;i++)
      {
          if(xs[i].sex)
              printf("%d,%d,%d,%d\n",xs[i].num,xs[i].score.boy.Longjump,xs[i].score.boy.Run,xs[i].score.boy.Shot);
          else
              printf("%d,%d,%d\n",xs[i].num,xs[i].score.girl.Situps,xs[i].score.girl.Skip);                      
                      }      
    system("pause");      
}
