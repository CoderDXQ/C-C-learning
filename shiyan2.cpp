#include <stdio.h>
#include <stdlib.h>
main()
{
      
      float sr=5*0.7;
      float sum=0;
      float fj=50*0.3;
      int i=0;
      do
      {
          sum+=sr;
          sr=sr*1.05;
          fj=fj*1.1;
          i++;
          
          }
      while (sum<fj);
      
      printf("%d",i);
      
      
      
      
      
      
    system("pause");      
}
