#include <stdio.h>
#include <stdlib.h>
main()
{
    int a[5]={1,3,5,7,9};
    int *num[5]={&a[0],&a[1],&a[2],&a[3],&a[4]};
    int **p,i;
    p=num;
    for(i=0;i<5;i++)
    {
                    
                    printf("%d ",** p);
                    p++;//使用指针的好处 
                    
                    }     
    printf("\n");
    for(i=0;i<5;i++)
        printf("%d ",*num[i]);
        printf("\n");
    for(i=0;i<5;i++)
        printf("%d ",num[i]);
    system("pause");      
}
