#include <stdio.h> 
#define N 2*a+2*a*a//���滻ֻ���ַ����滻����������������н���ǲ�ͬ�� 
main()
{
    int s,a;
    scanf("%d",&a);
    s=N+N*N;
    printf("s=%d\n",s);
    system("pause");
}
//������ #undef M ��ֹ�궨��  
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
