#include <stdio.h>
#include <stdlib.h>
main()
{
    char **p,*name[]={"China","Russia","France","America","Canada","Brazil"};
    int i;
    p=name;
    for(i=0;i<=5;i++)
    {
                     
      printf("%s,",*p++);               
                     
                     }
                     
     printf("\n");
    for(i=0;i<=5;i++)
    {
                     
      printf(" %s,",name[i]);  //  %sֻ�ܰѵ�ַ�����������ܴ�ֵ������ �����á�*name[i]��           
                     
                     }
    
 /*   printf("\n");      
    p=name; */            
    //printf("%c",**p);
    system("pause");      
}
