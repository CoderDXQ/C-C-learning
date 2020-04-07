#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
main()                                                                                                                                                                                                                                                                                                                                                                                                      
{
    FILE *fp;//文件都要用指针来操作 
    char ch;
    if((fp=fopen("D:\\A.TXT","wt"))==NULL)//wt只允许写 
    {
        printf("\n不能打开文件，按任意键退出程序！");
        getch();
        exit(1); 
    
    }
    printf("输入一行字符：\n");
    while((ch=getchar())!='\n')
    {
        fputc(ch,fp);
    }
    fclose(fp);//完成写进文件的操作
     
    if((fp=fopen("D:\\A.TXT","rt"))==NULL)//rt只允许读 
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1);                                      
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }//从文件读入字符 
    printf("\n");
    fclose(fp);
    
    system("pause");
}
