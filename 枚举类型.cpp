#include <stdio.h>
#include <stdlib.h> 
enum WEEKDAY{SUN=-5,MON,TUE,WED=100,THU,FRI=-6,SAT};
main()
{ 
    printf("%d,%d,%d,%d,%d,%d,%d",SUN,MON,TUE,WED,THU,FRI,SAT);
    system("pause");
}
