#include <stdio.h>
#include <stdlib.h>
#include <conio.h> 
main()                                                                                                                                                                                                                                                                                                                                                                                                      
{
    FILE *fp;//�ļ���Ҫ��ָ�������� 
    char ch;
    if((fp=fopen("D:\\A.TXT","wt"))==NULL)//wtֻ����д 
    {
        printf("\n���ܴ��ļ�����������˳�����");
        getch();
        exit(1); 
    
    }
    printf("����һ���ַ���\n");
    while((ch=getchar())!='\n')
    {
        fputc(ch,fp);
    }
    fclose(fp);//���д���ļ��Ĳ���
     
    if((fp=fopen("D:\\A.TXT","rt"))==NULL)//rtֻ����� 
    {
        printf("���ܴ��ļ�����������˳�");
        getch();
        exit(1);                                      
    }
    ch=fgetc(fp);
    while(ch!=EOF)
    {
        putchar(ch);
        ch=fgetc(fp);
    }//���ļ������ַ� 
    printf("\n");
    fclose(fp);
    
    system("pause");
}
