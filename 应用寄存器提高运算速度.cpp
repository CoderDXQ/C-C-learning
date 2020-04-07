#include<stdio.h>
#include<stdlib.h>
main()
{
    register int i;//直接将变量定义到CPU寄存器中 
    int sum=0;
    for(i=0;i<10000;i++)
        sum+=i;
    printf("%d\n",sum); 
      
    system("pause");      
}
