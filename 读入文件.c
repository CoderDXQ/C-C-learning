#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
main()                                                                                                                                                                                                                                                                                                                                                                                                      
{
    FILE *fp;
    char ch;
    
    
    if((fp=fopen("D:\\a.c","rt"))==NULL)
    {
        printf("\n���ܴ��ļ�����������˳�����");
        getch();
        exit(1); 
    
    }
    
    
    //����һ���Ǳ����е���·�������ж��Ƿ���ɴ��ļ��Ĺ��� 
    while((ch=fgetc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);//�ļ�������������ر� 
    system("pause");
}
