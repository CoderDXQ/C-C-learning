#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
main()
{
    FILE *fp;
    char ch,st[20];
    if((fp=fopen("D:\\a.txt","wt+"))==NULL)
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1); 
    }
    printf("输入一个字符串：\n");
    scanf("%s",st);
    fputs(st,fp);
    rewind(fp);
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    printf("\n");
    fclose(fp);
    system("pause");
}
