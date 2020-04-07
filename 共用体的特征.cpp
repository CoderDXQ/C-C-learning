#include <stdio.h>
#include <stdlib.h>
union A
{
       int x;
       char s[8];
       
       };

main()
{
      union A x={'A'};
      printf("%x\n",x.x);
      printf("%s\n",x.s); 
      system("pause");
      }
