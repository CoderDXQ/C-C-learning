#include <stdio.h>
#include <conio.h>//使用文件操作的头文件声明 
#include <stdlib.h>
void main()
{
    FILE *fp;//操作文件用的是指针 
    char str[11];
    if ((fp=fopen("D:\\a.txt","rt"))==NULL)
    {
        printf("\n不能打开文件，按任意键退出程序");
        getch();
        exit(1);
    }
    printf("%s\n",str);
    fgets(str,10,fp);//fgets(str, 5,fp);
    printf("%s\n",&str);
    fclose(fp);
    system("pause");
}
