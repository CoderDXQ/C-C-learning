#include <stdio.h> 
#include <stdlib.h>
char *week_name(char(*a)[10],int n);
main()
{
    char a[][10]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int x;
    printf("�������֣�0����6����");
    scanf("%d",&x);
        if(x>=0&&x<=6)
            printf("����%2d��Ӣ����д��%s\n",x,week_name(a,x));//a�����飬���Դ����ǵ�ַ 
        else                               
            printf("input error");     
    system("pause");      
}
char *week_name(char(*a)[10],int n)
{
     return a[n];
     }
