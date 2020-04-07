#include<stdlib.h>
#include<stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>

#define TRUE  1
#define FALSE 0
#define YES   1
#define NO    0
#define OK    1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define INFEASIBLE -1

#ifndef _MATH_H_
#define OVERFLOW -2
#define UNDERFLOW -3
#endif

#ifndef NULL
#define NULL((void*)0)
#endif

typedef int Status;

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


typedef int LElemType_L;

typedef struct LNode
{
    LElemType_L data;
    struct LNode* next;
}LNode;

typedef LNode* LinkList;

Status ListTraverse_L(LinkList L,void(Visit)(LElemType_L));
Status CreatList_HL(FILE *fp,LinkList *L,int n);
Status CreatList_TL(FILE *fp,LinkList *L,int n);
void MergeList_L(LinkList La,LinkList *Lb,LinkList *Lc);

void MergeList_L(LinkList La,LinkList *Lb,LinkList *Lc)
{
    LinkList pa,pb,pc;
    
    int ss;
    ss=0;

    pa=La->next;
    pb=(*Lb)->next;
    pc=(*Lc)=La;
    while(pa && pb)
    {
        if(pa->data <= pb->data)
        {
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else
        {
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    
    pc->next=pa?pa:pb;//等号用什么形式 
    free(*Lb);
    *Lb=NULL;
    
}

Status ListTraverse_L(LinkList L,void(Visit)(LElemType_L))
{
   LinkList p;
   if(!L)
       return ERROR;
   else
       p=L->next;
   while(p)
   {
       Visit(p->data);
       p=p->next;
   } 
   return OK;
}
Status CreateList_HL(FILE *fp,LinkList *L,int n)
{
    int i;
    LinkList p;
    LElemType_L tmp;
    
    *L=(LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next=NULL;
    
    for(i=1;i<=n;i++)
    {
        if(Scanf(fp,"%d",&tmp)==1)
        {
            p=(LinkList)malloc(sizeof(LNode));
            if(!p)
                exit(OVERFLOW);
            p->data=tmp;
            p->next=(*L)->next;
            (*L)->next=p;
        }
        else
            return ERROR;
    }
    return OK;
}
Status CreateList_TL(FILE *fp,LinkList *L,int n)
{
    int i;
    LinkList p,q;
    LElemType_L tmp;
    
    *L=(LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next=NULL;
    
    for(i=1,q=*L;i<=n;++i)
    {
        if(Scanf(fp,"%d",&tmp)==1)
        {
            p=(LinkList)malloc(sizeof(LNode));
            if(!p)
                exit(OVERFLOW);
            p->data=tmp;
            q->next=p;
            q=q->next;
        }
        else
            return ERROR;
            
    }    
    q->next=NULL;
    return OK;
}

void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}

void PrintElem(LElemType_L e);

int main()
{
    FILE *fp;
    LinkList La;
    LinkList Lb,Lc;
    int m;
    m=5;
    
    printf("作为示例，La长度设定为%d,Lb设定为%d,创建La和Lb\n",m,m);
    fp=fopen("TestData_HL.txt","r");
    CreateList_HL(fp,&La,m);
    fclose(fp);
    fp=fopen("TestData_TL.txt","r");
    CreateList_TL(fp,&Lb,m);
    fclose(fp);
    
    printf("La=");
    ListTraverse_L(La,PrintElem);
    printf("\n");
    printf("Lb=");
    ListTraverse_L(Lb,PrintElem);
    printf("\n\n");
    
    MergeList_L(La,&Lb,&Lc);
    printf("合并La和Lb为Lc=");
    ListTraverse_L(Lc,PrintElem);
    printf("\n\n");
    
    
    //return 0; 
   system("pause");
}






















































