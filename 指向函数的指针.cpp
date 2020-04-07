#include <stdio.h> 
#include <stdlib.h>
void GetMax(int x,int y,void(*pf)());
void put_cn(int x);
void put_en(int x);
main()
{
    int i,x=10,y=20;
    puts("中文1，英文2");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
         GetMax(x,y,put_cn);
         break;         
    case 2:
         GetMax(x,y,put_en);
         break;
             }      
    system("pause");      
}
void GetMax(int x,int y,void(*pf)())
{
     if(x>y)
        pf(x);
     else
        pf(y);
     }
void put_cn(int x)
{
     printf("最大值为：%d\n",x);
     }
int put_en(int x)
{
     
     printf("max number is:",x);
     
     }
