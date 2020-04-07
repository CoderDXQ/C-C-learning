#include <stdio.h>
#include <stdlib.h>
typedef int INT;
typedef int *PINT;
main()
{
    int a=10;
    INT b=10;
    PINT p;
    p=&a;
    *p+=b;
    printf("%d\n",a);
    system("pause");      
}
