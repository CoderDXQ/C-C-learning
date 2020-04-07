#include <stdio.h> 
#include <stdlib.h>
#include <EX.H>
int m;
void f(struct Ex x)
{
    printf("%d\n",x.x+m);
    system("pause");      
}
