#include <stdio.h>
#include <stdlib.h>
#define MAX(a,b) (a>b)?a:b
main()
{
    int a,b,max;
    scanf("%d%d",&a,&b);
    max=MAX(a,b);
    printf("max=%d\n",max);      
      
    system("pause"); 
} 
