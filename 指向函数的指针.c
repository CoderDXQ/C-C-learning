#include <stdio.h> 
#include <stdlib.h>
void GetMax(int x,int y,void(*pf)());
void put_cn(int x);
void put_en(int x);
void main()
{
    int i,x=10,y=20;
    puts("中文1，英文2");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
         GetMax(x,y,put_cn);//传函数就是传指针 ，函数就是指针 
         break;         
    case 2:
         GetMax(x,y,put_en);
         break;
             }      
    system("pause");      
}
void GetMax(int x,int y,void(*pf)())//函数指针的写法 
{
     if(x>y)
        pf(x);
     else
        pf(y);//两个py的指向是不同的 
     }
void put_cn(int x)
{
     printf("最大值为：%d\n",x);
     }
void put_en(int x)
{
     printf("max number is:%d\n",x);
     }
