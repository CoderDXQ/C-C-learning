#include <stdio.h> 
#define N 2*a+2*a*a//宏替换只是字符的替换，上下两个宏的运行结果是不同的 
main()
{
    int s,a;
    scanf("%d",&a);
    s=N+N*N;
    printf("s=%d\n",s);
    system("pause");
}
//可以用 #undef M 终止宏定义  
/*#include <stdio.h> 
#define N (2*a+2*a*a)
main()
{
    int s,a;
    scanf("%d",&a);
    s=N+N*N;
    printf("s=%d\n",s);
    system("pause");
}*/
