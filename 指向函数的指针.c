#include <stdio.h> 
#include <stdlib.h>
void GetMax(int x,int y,void(*pf)());
void put_cn(int x);
void put_en(int x);
void main()
{
    int i,x=10,y=20;
    puts("����1��Ӣ��2");
    scanf("%d",&i);
    switch(i)
    {
    case 1:
         GetMax(x,y,put_cn);//���������Ǵ�ָ�� ����������ָ�� 
         break;         
    case 2:
         GetMax(x,y,put_en);
         break;
             }      
    system("pause");      
}
void GetMax(int x,int y,void(*pf)())//����ָ���д�� 
{
     if(x>y)
        pf(x);
     else
        pf(y);//����py��ָ���ǲ�ͬ�� 
     }
void put_cn(int x)
{
     printf("���ֵΪ��%d\n",x);
     }
void put_en(int x)
{
     printf("max number is:%d\n",x);
     }
