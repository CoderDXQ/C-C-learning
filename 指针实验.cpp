#include <stdio.h>
#include <stdlib.h>

#define N 10
main()
{
    int i,j,a[4][3];
    int *p=a[0];
    int (*pp)[3]=a;
    for (i=0;i<4;i++)
        for (j=0;j<3;j++)
            scanf("%d",p++);
    p=a[0];
    for (i=0;i<4;i++)
    {
        for (j=0;j<3;j++)
            printf("%3d",pp[i][j]);
            //�������ָ�룬ָ��������� 
            
        printf("\n");        
    }   
    
    
    
            system("pause");
}
