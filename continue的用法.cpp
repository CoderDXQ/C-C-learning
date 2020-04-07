#include <stdio.h>
#include <stdlib.h>
main()
{
      int i,c;
      c=0;
      for(i=10;i<99;i++)
      {
      if (i%5!=0) continue;
      printf("%d   ",i);
      c++;
      if (c%5==0) printf("\n");                  
      }
      printf("\n");
      
      
      
      
     system("pause");      
} 
