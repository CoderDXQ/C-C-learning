#include <stdio.h> 
#include <stdlib.h>
struct Ex1
{
       short x:5;
       unsigned short y:5;
};
main()
{
    struct Ex1 x;
    x.x=30;
    x.y=30;
    printf("%d\n",x.x);
    printf("%d\n",x.y);
    system("pause");      
}
