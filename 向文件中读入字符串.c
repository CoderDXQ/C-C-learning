#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
main()
{
    FILE *fp;
    char str[11];
    if (fp=fopen("D:\\a.txt","rt")==NULL)
    {
        printf("\n���ܴ��ļ�����������˳�����");
        getch();
        exit(1);
    }
    fgets(str,11,fp);
    printf("%s\n",str);
    fclose(fp);
    system("pause");
}
