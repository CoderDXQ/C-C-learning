#include <stdio.h>
#include <stdlib.h>

main()
{
      int m,n,r;
      printf("输入两个自然数：\n");
      scanf("%d,%d",&m,&n);
      printf("%d,%d的最大公约数",m,n);
      r=m%n;
      while(r!=0)
      {
                 m=n;
                 n=r;
                 r=m%n;
             }
      printf("%d\n",n);
      system("pause");
}
