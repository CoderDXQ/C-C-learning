#include <stdio.h>
#include <stdlib.h>
#include <math.h>
main()
{
      double a,b,c,d,a2,x1,x2;
      printf("input a,b,c\n");
      scanf("%lf,%lf,%lf",&a,&b,&c);
      if (a==0)
      {
               x1=-c/b;
               printf("root=%.2f\n",x1);
              
              }
      else
      {
          d=b*b-4*a*c;
          a2=2*a;
          x1=-b/a2;
          if(d>=0)
              {
                  x2=sqrt(d)/a2;
                  printf("real root:\n");
                  printf("root1=%.2f,root=%.2f\n",x1+x2,x1-x2);
                   
              }
          else
              {
                   x2=sqrt(-d)/a2;
                   printf("complex root:\n");
                   printf("root1=%.2f+%.2fi\n",x1,x2);
                   printf("root1=%.2f+%.2fi\n",x1,x2);
                   
              
              
              
              }
      
      
      
      
      
      
      }
      
      
 
      
      system("pause");
}
