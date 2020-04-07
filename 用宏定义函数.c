#include <stdio.h>
#include<stdlib.h>
#define SA(x) (x)*(x)
main()
{
    int a,s;
    scanf("%d",&a);
    s=SA(a+1);
    printf("s=%d\n",s);
    system("pause");
}
