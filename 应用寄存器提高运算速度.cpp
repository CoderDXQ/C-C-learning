#include<stdio.h>
#include<stdlib.h>
main()
{
    register int i;//ֱ�ӽ��������嵽CPU�Ĵ����� 
    int sum=0;
    for(i=0;i<10000;i++)
        sum+=i;
    printf("%d\n",sum); 
      
    system("pause");      
}
