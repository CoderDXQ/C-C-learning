#include <stdio.h>
#include <stdlib.h>

main()
{
      int x;
      int s=0;
      scanf("%d",&x);
      while(x>0)
      {
                s+=x%10;
                x=x/10;
                
      }
      printf("%d\n",s);
      
      
      
      
      system("pause");
      
      
      
      
      
      
      
}
