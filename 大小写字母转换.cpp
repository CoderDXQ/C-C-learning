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
        if(convert(&str[i])) iCount++;//传的是地址 
    printf("成功转换小写字母%d个,转换结果为：%s\n",iCount,str);      
      
    system("pause");      
}
int convert(char *pch)//直接用指针来做不必考虑作用域的问题 
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
int convert (char *pch);//用函数时必须有声明                                     
main()
{
    char str[100];
    int iCount=0;
    gets(str);
    iCount=convert(str);
    printf("成功转换小写字母%d个，转换结果为：%s\n",iCount,str);
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
        }while(pch[++i]);//do  while 的逻辑决定了”++i“ 
    return iCount;
    }















