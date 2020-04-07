#include <stdio.h>
#include <stdlib.h>
unsigned fun(int n)
{
    unsigned *a,i;
    a=malloc((n+1)*sizeof(int));
    if(a=NULL)
        return -1;
    a[1]=1;
    a[2]=1;
    for(i=0;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    i=a[n];
    free(a);
    return i;         
}
main()
{
    int x;
    scanf("%d",&x);
    printf("%u\n",fun(x));
    system("pause");      
}
