#include <stdio.h> 
#include <stdlib.h>
main()
{
      int i,n;
      scanf("%d",&n);
      for (i=2;i<n;i++)
      {
          if (n%i==0) break;
          }      
      if (i==n)
      printf("shi");
      else
      printf("bushi");
      
      
      
      
    system("pause");      
} 
