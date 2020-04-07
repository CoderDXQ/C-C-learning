#include <stdio.h>
#include <stdlib.h>
main()
{
      int i,j;
      i=1;
      do
      {
          j=1;
          do
          {
              printf("%d * %d=%2d",j,i,i*j);
              j++;
              
          }while(j<=i); 
          
      i++;
      printf("\n");
          
      }while(i<=9);
          
      
      
      
      
      
      
      system("pause");
}
