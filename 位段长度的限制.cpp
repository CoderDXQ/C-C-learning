#include <stdio.h>
#include <stdlib.h>
struct Ex1
{
       short x:9;
       short y:9;
       short z:9;
};
struct Ex2
{
       int x:9;
       int  y:9;
       int z:9;
};
struct Ex3
{
       int x:9;
       int :0;
       int z:9;
};
main()
{
      printf("%d\n",sizeof(struct Ex1));
      printf("%d\n",sizeof(struct Ex2));
      printf("%d\n",sizeof(struct Ex3));
      system("pause");
}
