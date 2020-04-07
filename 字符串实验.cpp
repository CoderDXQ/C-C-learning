#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
# define N 1024
main()
{
    int a[2][3],*pa[2],*t;
    int i,j;
    pa[0]=a[0];
    pa[1]=a[1];
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
            a[i][j]=(i+1)*(j+1);
    for(i=0;i<2;i++)
        for(j=0;j<3;j++)
        {
                        
        printf("a[ %d][ %d]:%d\n",i,j,*pa[i]);//输出要加取值符号“*” 
        pa[i]++;
                 }      
                                                
    system("pause");      
}
