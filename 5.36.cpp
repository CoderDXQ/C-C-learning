#include <stdio.h>
#include <stdlib.h>
main()
{
    int x=100;
    int *p1=&x;
    int **p2=&p1;
    int ***p3=&p2;
    printf("%d\n",*p1);
    printf("%d\n",**p2);
    printf("%d\n",***p3);
      
      
      
      
      
      
    system("pause");      
}
