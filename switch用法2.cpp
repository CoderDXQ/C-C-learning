#include <stdio.h>
#include <stdlib.h>
main()
{
      float a,b,result;
      char op;
      scanf("%f,%f,%c",&a,&b,&op);
      switch(op)
      {
      case '+':
           result=a+b;break;
      case '-':
           result=a-b;break;
      case '*':
           result=a*b;break;
      case '/':
           result=a/b;break;          
                
      }
      printf("result=%f\n",result);
      system("pause");
      
      
}


