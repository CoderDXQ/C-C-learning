#include <stdio.h> 
#include <stdlib.h>
int add(int x,int y); 
int sub(int x,int y);
int mul(int x,int y);
void exec(int x,int y,int(*pf)(int x,int y));
void main()
{
    int a,b,i;
    char c;
    int(*pf[])(int x,int y)={add,sub,mul};
    puts("请输入表达式：");
    scanf("%d%c%d",&a,&c,&b);
    switch(c)
    {
    case '+':
         i=0;
         break;
    case '-':
         i=1;
         break;
    case '*':
         i=2;
         break;
             }
    exec(a,b,pf[i]);//指针就是数组，数组就是指针 
    system("pause");      
}
int add(int x,int y)
{
    return(x+y);
    } 
int sub(int x,int y)
{
    return(x-y);
    } 
int mul(int x,int y)
{
    return(x*y);
    } 
void exec(int x,int y,int(*pf)(int x,int y))
{
     
     printf("%d\n",(*pf)(x,y)); 
     
     }
