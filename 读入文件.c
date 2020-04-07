#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
main()                                                                                                                                                                                                                                                                                                                                                                                                      
{
    FILE *fp;
    char ch;
    
    
    if((fp=fopen("D:\\a.c","rt"))==NULL)
    {
        printf("\n不能打开文件，按任意键退出程序！");
        getch();
        exit(1); 
    
    }
    
    
    //以上一段是必须有的套路，用来判断是否完成打开文件的工作 
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);//文件打开在用完后必须关闭 
    system("pause");
}
