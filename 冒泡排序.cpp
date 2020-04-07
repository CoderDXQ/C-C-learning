#include <stdio.h>
#include <stdlib.h>
# define N 10
main()
{
      int i,j,t,a[N];
      for (i=0;i<10;i++) scanf("%d",&a[i]);
      for (i=0;i<N-1;i++)
      {
          for (j=0;j<N-i;j++)
              if (a[j]>a[j+1])
               {
                   t=a[j];
                   a[j]=a[j+1];
                   a[j+1]=t;  
                              }           
      }
      for (i=0;i<10;i++) printf("%d ",a[i]);
      system("pause");
}
