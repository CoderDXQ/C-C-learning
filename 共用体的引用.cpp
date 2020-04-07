#include <stdio.h>
struct A
{
       int x;
       int y;
}; 
union B
{
      struct A a;
      int x;
      char s[6];
      };
void main()
{
     union B x;
     union B *p=&x;
     
     x.x=0x12345678;
     x.a.x=0x99;
     p->s[2]=0x77;
     printf("%x\n",(*p).x);     
     
     }
