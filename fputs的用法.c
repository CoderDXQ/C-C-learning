#include <stdio.h>
#include  <conio.h>
#include <stdlib.h>
main()
{
    FILE *fp;
    char ch,st[20];
    if((fp=fopen("D:\\a.txt","wt"))==NULL)
    {
        printf("���ܴ��ļ�����������˳�");
        getch();
        exit(1);
    }
    printf("����һ���ַ���\n");
    scanf("%s",st);
    fputs(st,fp);//�����ļ��������õĶ���ָ�� 
    fclose(fp);
    if((fp=fopen("D:\\a.txt","rt"))==NULL)
    {
        printf("���ܴ��ļ�����������˳�");
        getch();
        exit(1); 
    }//���´��ļ���ָ��fp���ļ���ͷ������Ҫ��rewind�������� 
    while((ch=fgetc(fp))!=EOF)
    {
    putchar(ch);
    }
    printf("\n");
    fclose(fp);




    system("pause");
}
