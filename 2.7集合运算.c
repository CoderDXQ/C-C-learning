#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define MAXSIZE 1000
#define TRUE  1
#define FALSE 0
#define YES   1
#define NO    0
#define OK    1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define UNDERFLOW -3

#ifndef NULL
#define NULL((void*)0)
#endif

typedef int Status;
typedef int SLinkList;
typedef int LElemType_S;
typedef struct
{
    LElemType_S data;
    int cur;
}Component[MAXSIZE];

Component SPACE;

void InitSpace_SL();
int Malloc_SL();
void Free_SL(int k);
Status ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S));
void PrintElem(LElemType_S e);

void difference(SLinkList *S,LElemType_S A[],int len_A,LElemType_S B[],int len_B);


int Scanf(FILE *fp,char *format,...)
{
    int *i;
    char *ch,*s;
    float *f;
    int count,k,len,n;
    int tmp;
    va_list ap;
    
    len=strlen(format);
    
    va_start(ap,format);
    
    for(count=0,k=2;k<=len;k=k+2)
    {
        while((tmp=getc(fp))!=EOF)
        {
            if(tmp>=0 &&tmp<=127)
            {ungetc(tmp,fp);break;}
        }
        
        if (tmp==EOF) break;
        
        if(format[k-1]=='c')//读取字符 
        {
            ch=va_arg(ap,char*);
            
            if(tmp!=EOF)
                count+=fscanf(fp,"%c",ch);
        }
        
        if(format[k-1]=='d')//读取整型 
        {
            i=va_arg(ap,int*);
            while((tmp=getc(fp))!=EOF)
            {
                if((tmp>='0'&&tmp<='9')||tmp=='-'||tmp=='+')
                {
                    ungetc(tmp,fp);break;
                }
            } 
            if(tmp!=EOF)
                count+=fscanf(fp,"%d",i);
        }
        
        if(format[k-1]=='f')//读取浮点型 
        {
            f=va_arg(ap,float*);
            while((tmp=getc(fp))!=EOF)
            {
                if((tmp>='0'&&tmp<='9')||tmp=='-'||tmp=='+'||tmp=='.')
                {
                    ungetc(tmp,fp);break;
                }
            }
            if(tmp!=EOF)
                count+=fscanf(fp,"%f",f);
        }
        
        if(format[k-1]=='s')//读取字符串 
        {
            s=va_arg(ap,char*);//tmp==“”，中间是空格还是没有字符分不清楚 
            while((tmp=getc(fp))!=EOF &&(!isprint(tmp)||tmp==' '));
            
            n=0;
            if(!feof(fp))
            {
                ungetc(tmp,fp);
                while(tmp=getc(fp)!=EOF)
                {
                    if(isprint(tmp)&&tmp!=' ')
                        s[n++]=tmp;
                    else
                        break;
                }
                ungetc(tmp,fp);
            }
            s[n]='\0';
            count++;
        } 
    }
    
    va_end(ap);
    
    return count;    
}














void PrintElem(LElemType_S e)
{
    printf("%d ",e);
}

void InitSpace_SL()
{
   int i;
   for(i=0;i<MAXSIZE-1;i++)
       SPACE[i].cur=i+1;//.cur是指序号 
   SPACE[MAXSIZE-1].cur=0; //最后一个标记为0 
}
int Malloc_SL()
{
    int i;
    i=SPACE[0].cur;//i=1 
    if(SPACE[0].cur)//SPACE[0].cur=1 
    {
        SPACE[0].cur=SPACE[i].cur;//SPACE[0].cur=2
        return i;
    }
    else
        return 0;
        
        
}
void Free_SL(int k)
{
    SPACE[k].cur=SPACE[0].cur;
    SPACE[0].cur=k;
}

Status ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S))
{
    int p;
    if(!H)
        return ERROR;
    p=SPACE[H].cur;
    while(p)
    {
        Visit(SPACE[p].data);
        p=SPACE[p].cur;
    }
    return OK;
}
void difference(SLinkList *S,LElemType_S A[],int len_A,LElemType_S B[],int len_B)
{
    int i,j;
    int r,p,k;
    LElemType_S b;
    
    InitSpace_SL();
    *S=Malloc_SL();
    r=*S;
    SPACE[r].cur=0;
    //
    //printf("*******%d",r);
    //
    for(j=0;j<len_A;j++)
    {
                        
        i=Malloc_SL();
        
        SPACE[i].data=A[j];
        SPACE[r].cur=i;
        r=i;
    }    
    //********
    /*
    for(j=0;j<len_A;j++)
    {
    printf("%d ",SPACE[j].data);
    printf("\n\n");
    }*/
    //***********
    
    SPACE[r].cur=0;
    
    for(j=0;j<len_B;j++)
    {
        b=B[j];
        p=*S;
        k=SPACE[*S].cur;
        while(k && SPACE[k].data!=b)
        {
            p=k;
            k=SPACE[k].cur;
        }
    }
    if(!k)
    {
        i=Malloc_SL();
        SPACE[i].data=b;
        SPACE[i].cur=SPACE[r].cur;
        SPACE[r].cur=i;
    }
    else
    {
        SPACE[p].cur=SPACE[k].cur;
        Free_SL(k);
        if(k==r)
            r=p;
    }
    
   // for(i=0;i<=3;i++)
     //   printf("%d ",S[i]);
    
    
}





int main()
{
    SLinkList S;
    FILE *fp;
    int len_A,len_B,i;
    LElemType_S A[100],B[100];
    len_A=3;
    len_B=5;
    
    fp=fopen("TestData.txt","r");
    for(i=0;i<len_A;i++)
        Scanf(fp,"%d",&A[i]); 
    for(i=0;i<len_B;i++)
        Scanf(fp,"%d",&B[i]);
    fclose(fp);
    
    printf("A="); 
    for(i=0;i<len_A;i++)
        PrintElem(A[i]);
    printf("\n");
    printf("B=");
    for(i=0;i<len_B;i++)
        PrintElem(B[i]);
    printf("\n\n");
    
    printf("S=(A-B)U(B-A)=");
    difference(&S,A,len_A,B,len_B);
    ListTraverse_SL(S,PrintElem);
    printf("\n\n");
    
    system("pause");
}

























