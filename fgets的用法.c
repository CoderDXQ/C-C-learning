#include <stdio.h>
#include <conio.h>//ʹ���ļ�������ͷ�ļ����� 
#include <stdlib.h>
void main()
{
    FILE *fp;//�����ļ��õ���ָ�� 
    char str[11];
    if ((fp=fopen("D:\\a.txt","rt"))==NULL)
    {
        printf("\n���ܴ��ļ�����������˳�����");
        getch();
        exit(1);
    }
    printf("%s\n",str);
    fgets(str,10,fp);//fgets(str, 5,fp);
    printf("%s\n",&str);
    fclose(fp);
    system("pause");
}
