#include<stdio.h>
#include<stdlib.h>
int fac(int n)
{
    static int f=1;
    f=f*n;
    return(f);
    
    }
void main()
{
     int i;
     for(i=0;i<=5;i++)
         printf("%d!=%d\n",i,fac(i)); 
      
    system("pause");      
}
