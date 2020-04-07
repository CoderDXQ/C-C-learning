#include <stdio.h>
#include <stdlib.h>
typedef int *T0;
typedef T0 *T1[20];
typedef T1 *T2[10];
typedef T2 *T3;
main()
{
      int x=100;
      T0 a;
      T1 b;
      T2 c;
      T3 d;
      a=&x;
      b[0]=&a;
      c[0]=&b;
      d=&c;
      printf("%d",******d);
    system("pause");      
}
