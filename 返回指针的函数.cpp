#include <stdio.h> 
#include <stdlib.h>
char *week_name(char(*a)[10],int n);
main()
{
    char a[][10]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int x;
    printf("输入数字（0——6）：");
    scanf("%d",&x);
        if(x>=0&&x<=6)
            printf("星期%2d的英文缩写是%s\n",x,week_name(a,x));//a是数组，所以传的是地址 
        else                               
            printf("input error");     
    system("pause");      
}
char *week_name(char(*a)[10],int n)
{
     return a[n];
     }
