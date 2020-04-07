#include "stdio.h"
#include <stdlib.h>
#include <string.h>

main()
{
    float mark;
    char grade;
    printf("please input a mark:");
    scanf("%f",&mark);
    switch((int)(mark/10))
    {
        case 10:
        case  9:grade='A';break;
        case  8:grade='B';break;
        case  7:grade='C';break;
        case  6:grade='D';break;
        case  5:
        case  4:
        case  3:
        case  2:
        case  1:
        case  0:grade='E'; 
                                               
     }
     printf("Mark=%5.1f,Grade=%c\n",mark,grade);
    system("pause");

}

