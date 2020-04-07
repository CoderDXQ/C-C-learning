#include <stdio.h> 
#include <stdlib.h>
struct Ex1
{
       short x:5;
       
       };
struct Ex2
{
       char x:5;
       
       };
void main()
{
      printf("%d\n",sizeof(struct Ex1));
      printf("%d\n",sizeof(struct Ex2));
       //eturn 0;
    system("pause");      
}
