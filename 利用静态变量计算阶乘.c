#include<stdio.h>
#include<stdlib.h>
int fac(int n)
{
    static int f=1;//静态变量的值不会在退出函数后释放 
    f=f*n;
    return(f);
    
    }
void main()
{
     int i;
     for(i=1;i<=5;i++)
         printf("%d!=%d\n",i,fac(i)); 
      
    system("pause");      
}
