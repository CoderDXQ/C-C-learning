#include<stdio.h>
#include<stdlib.h>
f(int a)
{
    auto b=0;//b���Զ�������ÿ�ν��뺯��b�������¸�ֵΪ0 
    static c=3;//c�Ǿ�̬������ֻ�е�һ�ν���ʱ��ֵ���Ժ���벻�������¸�ֵ 
    b=b+1;
    c=c+1;
    printf("b=%d,c=%d,",b,c); 
    return(a+b+c);
      } 
main()
{
    int a=2,i;
    for(i=0;i<3;i++)
        printf("a+b+c=%d\n",f(a));
      
    system("pause");      
}
