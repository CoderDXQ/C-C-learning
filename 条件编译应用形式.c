/*#include <stdio.h>
#include<stdlib.h>
#define MAX 100 
main()
{
    int i=10;
    float x=12.5;
#ifdef MAX
    printf("%d\n",i);
#else
    printf("%.1f\n",x);
#endif
    printf("%d,%.1f\n",i,x);
    system("pause");
} 
*/ 

#include <stdio.h>
#include<stdlib.h>
#define M 5
main()
{
    int a=1;
    float c,s,r;
    printf("input a number:");
    scanf("%f",&c);
#if (M!=5)
    r=3.14159*c*c;
    printf("area of round is :%f\n",r); 
#else 
    s=c*c;
    printf("area of square is :%f\n",s);
#endif     
    system("pause");
}         

