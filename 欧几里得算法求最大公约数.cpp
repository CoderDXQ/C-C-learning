#include <stdio.h>
#include <stdlib.h>

main()
{
      int m,n,r;
      printf("����������Ȼ����\n");
      scanf("%d,%d",&m,&n);
      printf("%d,%d�����Լ��",m,n);
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
