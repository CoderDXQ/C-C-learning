#include <stdio.h> 
#include <stdlib.h>
int fun(int n)
{
    if(n==1||n==2)
        return(1);
    else 
        return(fun(n-1)+fun(n-2));
}
main()
{
    int x;
    x=fun(40); 
    printf("%d\n",x);
    system("pause");      
}
