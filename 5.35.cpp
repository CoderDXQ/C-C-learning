#include <stdio.h>
#include <stdlib.h>
main()
{
      int a[3][3]={1,2,3,4,5,6,7,8,9};
      int *pa[3]={a[0],a[1],a[2]};
      int *p=a[0],i;
      for(i=0;i<3;i++)
          printf("%d, %d, %d\n",a[i][2-i],*a[i],*(*(a+i)+i));
      
      for(i=0;i<3;i++)
          printf("%d, %d, %d\n",*pa[i],p[i],*(p+i));
          
          
          printf("%d\n",p[4]);//指针就是数组，数组就是指针 
      
      
      
      
      
      
    system("pause");      
}
