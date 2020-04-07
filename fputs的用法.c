#include <stdio.h>
#include  <conio.h>
#include <stdlib.h>
main()
{
    FILE *fp;
    char ch,st[20];
    if((fp=fopen("D:\\a.txt","wt"))==NULL)
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1);
    }
    printf("输入一个字符串\n");
    scanf("%s",st);
    fputs(st,fp);//操作文件和数组用的都是指针 
    fclose(fp);
    if((fp=fopen("D:\\a.txt","rt"))==NULL)
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1); 
    }//重新打开文件后，指针fp在文件开头，不需要用rewind函数重置 
    while((ch=fgetc(fp))!=EOF)
    {
    putchar(ch);
    }
    printf("\n");
    fclose(fp);




    system("pause");
}
