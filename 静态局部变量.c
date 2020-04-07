#include<stdio.h>
#include<stdlib.h>
f(int a)
{
    auto b=0;//b是自动变量，每次进入函数b都被重新赋值为0 
    static c=3;//c是静态变量，只有第一次进入时赋值，以后进入不会再重新赋值 
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
