#include <stdio.h> 
#include <stdlib.h>
extern int x;
int x=100; 
void f()
{
     x=50;
     printf("%d\n",x);
     }
void main()
{
     printf("%d\n",x);
     f();
     printf("%d\n",x); 
    system("pause");      
}
 
