#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
main()
{
    FILE *fp;
    char ch,st[20];
    if((fp=fopen("D:\\a.txt","wt+"))==NULL)
    {
        printf("���ܴ��ļ�����������˳�");
        getch();
        exit(1); 
    }
    printf("����һ���ַ�����\n");
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
