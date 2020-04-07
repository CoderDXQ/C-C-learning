#include <stdio.h>
#include <stdlib.h>
main()
{
      int i,j,c;
      c=0;
      for(i=3;i<=99;i=i+2)
      {
          for (j=2;j<=i-1;j++)
            if (i % j==0) break;
          if(j>i-1)
              {
                   printf("%d ",i);
                   c++;
                   if (c%5==0) printf("\n");
                   }
      }
      printf("\n");
      system("pause");
}
