/*
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
int convert(char *pch); 
main()
{
    char str[100];
    int i,l,iCount=0;
    gets(str);
    l=strlen(str);
    for(i=0;i<l;i++)
        if(convert(&str[i])) iCount++;//�����ǵ�ַ 
    printf("�ɹ�ת��Сд��ĸ%d��,ת�����Ϊ��%s\n",iCount,str);      
      
    system("pause");      
}
int convert(char *pch)//ֱ����ָ���������ؿ�������������� 
{
    if(*pch>='a'&&*pch<='z')
    {
        *pch+=('A'-'a');
        return 1;                        
    } 
    return 0;
}
*/
#include <stdio.h> 
#include <stdlib.h>
int convert (char *pch);//�ú���ʱ����������                                     
main()
{
    char str[100];
    int iCount=0;
    gets(str);
    iCount=convert(str);
    printf("�ɹ�ת��Сд��ĸ%d����ת�����Ϊ��%s\n",iCount,str);
    system("pause");      
}
int convert(char *pch)
{
    int i=0,iCount=0;
    do
    {
        if(pch[i]>='a'&&pch[i]<='x')
        {
            pch[i]+=('A'-'a');
            iCount++;               }
        }while(pch[++i]);//do  while ���߼������ˡ�++i�� 
    return iCount;
    }















