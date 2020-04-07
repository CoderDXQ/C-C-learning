#include <stdio.h> 
#include <stdlib.h>
#define MAX 76                                                                                                                                                                                     
int fun(int n)
{
    int a[MAX],i;
    if(n>=MAX)
        return -1;
    a[1]=1;a[2]=1;
    for(i=3;i<=n;i++)
        a[i]=a[i-1]+a[i-2];
    return a[n];
    }
main()
{
    int x;
    x=fun(40);
    printf("%d\n",x);     
    system("pause");      
}
