#include <stdio.h>
#include <stdlib.h>
enum WEEKDAY{SUN,MON,TUE,WED,THU,FRI,SAT};
main()
{    enum WEEKDAY x;
     int i;
     while(1)
     {
         printf("��������������ڼ���");
         scanf("%d",&i);
         if  (i>=0&&i<=6)
             break;
         printf("�������\n");
         }
     switch(i)
     {
         case 0:
              x=SUN;
              break;
         case 1:
              x=MON;
              break;
         case 2:
              x=TUE;
              break;
         case 3:
              x=WED;
              break;
         case 4:
              x=THU;
              break;
         case 5:
              x=FRI;
              break;
         case 6:
              x=SAT;
              break;
              }
         printf("%d",x
         ) ;
    system("pause");      
}
