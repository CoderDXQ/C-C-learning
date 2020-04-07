#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define epsilon 1.0e-6
main()
{
      double x,d;
      x=1.5;
      do{
            d=(((2*x-4)*x+3)*x-6)/((6*x-8)*x+3);
            x=x-d;
            }
      while (fabs(d)>epsilon);
      
      printf("%6.2f\n",x);
    system("pause");      
}
