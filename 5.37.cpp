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
                     
      printf(" %s,",name[i]);  //  %s只能把地址传过来，不能传值，所以 不能用“*name[i]”           
                     
                     }
    
 /*   printf("\n");      
    p=name; */            
    //printf("%c",**p);
    system("pause");      
}
