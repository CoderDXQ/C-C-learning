#include <stdio.h>
#include <stdlib.h>
main()
{
      double sr,sum,fj;
      double r=1;
      int i=0;
      while (1)
      {
            sr=5*0.7;
            sum=0;
            fj=50*0.3;
            i=0;
            r=r+0.001;
            do
            {
            sum+=sr;
            sr=sr*r;
            fj=fj*1.1;
            i++;
                      }
                      
            while(sum<fj);
            if (i<6)
            {
                    printf("%.2f%\n",(r-1)*100);
                    break;
                    }                   
            }
      system("pause");
                  
}
