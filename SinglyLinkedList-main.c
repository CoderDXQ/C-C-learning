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
//**************** 



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


//*************
typedef int LElemType_L;

typedef struct LNode
{
    LElemType_L data;
    struct LNode* next;
}LNode;
typedef LNode* LinkList;


Status InitList_L(LinkList *L);
Status ClearList_L(LinkList L);
void DestroyList_L(LinkList *L);
Status ListEmpty_L(LinkList L);
int ListLength_L(LinkList L);
Status GetElem_L(LinkList L,int i,LElemType_L *e);
int LocateElem_L(LinkList L,LElemType_L e,Status(Compare)(LElemType_L,LElemType_L));
Status PriorElem_L(LinkList L,LElemType_L cur_e,LElemType_L *pre_e);
Status NextElem_L(LinkList L,LElemType_L cur_e,LElemType_L *next_e);
Status ListInsert_L(LinkList L,int i,LElemType_L e);
Status ListDelete_L(LinkList L,int i,LElemType_L *e);
Status ListTraverse_L(LinkList L,void(Visit)(LElemType_L));
Status CreatList_HL(FILE *fp,LinkList *L,int n);
Status CreatList_TL(FILE *fp,LinkList *L,int n);


Status InitList_L(LinkList *L)
{
    (*L)=(LinkList)malloc(sizeof(LNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next=NULL;
    return OK;
}
Status ClearList_L(LinkList L)
{
    LinkList pre,p;
    if(!L)
        return ERROR;
    pre=L->next;
    while(pre)
    {
        p=pre->next;
        free(pre);
        pre=p;
    }
    L->next=NULL;
    return OK;
}
void DestroyList_L(LinkList *L)
{
    LinkList p=*L;
    while(p)
    {
        p=(*L)->next;
        free(*L);
        (*L)=p;
    }
}
Status ListEmpty_L(LinkList L)
{
    if(L!=NULL && L->next==NULL)
        return TRUE;
    else
        return FALSE;
}
int ListLength_L(LinkList L)
{
    LinkList p;
    int i;
    if(L)
    {
        i=0;
        p=L->next;
        while(p)
        {
            i++;
            p=p->next;
        }
    }
    return i;
}
Status GetElem_L(LinkList L,int i,LElemType_L *e)
{
    int j;
    LinkList p=L->next;
    j=1;
    p=L->next;
    
    while(p&&j<i)
    {
        j++;
        p=p->next;
    }
    if(!p||j>i)
        return ERROR;
        
    *e=p->data;
    return OK;
}
int LocateElem_L(LinkList L,LElemType_L e,Status(Compare)(LElemType_L,LElemType_L))
{
    int i;
    LinkList p;
    i=-1;
    if(L)
    {
        i=0;
        p=L->next;
        while(p)
        {
            i++;
            if(!Compare(e,p->data))
                p=p->next;
            else
                break;
        }
    }
    return i;
}
Status PriorElem_L(LinkList L,LElemType_L cur_e,LElemType_L *pre_e)
{
    LinkList p,suc;
    if(L)
    {
         p=L->next;
         if(p->data!=cur_e)
         {
             while(p->next)
             {
                 suc=p->next;
                 if(suc->data==cur_e)
                 {
                     *pre_e=p->data;
                     return OK;
                 }
                 p=suc;
             }
         }
    }
    return ERROR;
}
Status NextElem_L(LinkList L,LElemType_L cur_e,LElemType_L *next_e)
{
    LinkList p,suc;
    if(L)
    {
         p=L->next;
         while(p&&p->next)
         {
             suc=p->next;
             if(suc&&p->data==cur_e)
             {
                 *next_e=suc->data;
                 return OK;
             }
             if(suc)
                 p=suc;
             else
                 break;
         }
    }
    return ERROR;
    
}
Status ListInsert_L(LinkList L,int i,LElemType_L e)
{
    LinkList p,s;
    int j;
    p=L;
    j=0;
    while(p&&j<i-1)
    {
        p=p->next;
        ++j;
    }
    if(!p&&j>i-1)
       return ERROR;
    s=(LinkList)malloc(sizeof(LNode));
    if(!s)
        exit(OVERFLOW);
    s->data=e;
    s->next=p->next;
    p->next=s;
    return OK;
}
Status ListDelete_L(LinkList L,int i,LElemType_L *e)
{
    LinkList pre,p;
    int j;
    pre=L;
    j=1;
    while(pre->next&&j<i)
    {
        pre=pre->next;
        ++j;
    }
    if(!pre->next||j>i)
        return ERROR;
    p=pre->next;
    pre->next=p->next;
    *e=p->data;
    free(p);
    
    return OK;
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

Status CmpGreater(LElemType_L e,LElemType_L data)
{
    return data>e?TRUE:FALSE;
}
void PrintElem(LElemType_L e)
{
    printf("%d ",e);
}










Status CmpGreater(LElemType_L e,LElemType_L data);
void PrintElem(LElemType_L e);

int main()
{
    LinkList L;
    int i;
    LElemType_L e;
    
    printf("InitList_L测试\n");
    {
        printf("初始化单链表\n");
        InitList_L(&L);
        printf("\n");
    }
    printf("ListEmpty_L测试\n");
    {
        ListEmpty_L(L)?printf("L为空\n"):printf("L不为空"); 
        printf("\n");
    }
    printf("ListInsert_L测试\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("在L第%d个位置插入\"%d\"...\n",i,2*i);
            ListInsert_L(L,i,2*i);
        }
        printf("\n");
    }
    printf("ListTraverse_L测试\n");
    {
        printf("L中的元素为：L=\n");
        ListTraverse_L(L,PrintElem); 
        
        printf("\n\n");
    }
    printf("ListLength_L测试\n");
    {
        printf("L的长度为%d\n",ListLength_L(L));
        printf("\n");
    }
    printf("ListDelete_L测试\n");
    {
        ListDelete_L(L,6,&e);
        printf("删除L中第6个元素为L=\n");
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    printf("GetElem_L测试\n");
    {
        GetElem_L(L,4,&e);
        printf("L中第4个位置的元素为\"%d\"\n",e);
        printf("\n");
    }
    printf("LocateElem_L测试\n");
    {
        i=LocateElem_L(L,7,CmpGreater);
        printf("L中第一个元素值大于\"7\"的元素位置为%d\n",i);
        printf("\n");
    }
    printf("PriorElem_L测试\n");
    {
        PriorElem_L(L,6,&e);
        printf("元素\"6\"的前驱为\"%d\"\n",e);
        printf("\n");
    }
    printf("NextElem_L测试\n");
    {
        NextElem_L(L,6,&e);
        printf("元素\"6\"的后继为\"%d\"\n",e);
        printf("\n");
    }
    printf("ClearList_L测试\n");
    {
        printf("清空L前：");
        ListEmpty_L(L)?printf("L为空\n"):printf("L不为空\n");
        ClearList_L(L);
        printf("清空L后：");
        ListEmpty_L(L)?printf("L为空\n"):printf("L不为空\n");
        printf("\n");
    }
    printf("DestroyList_L测试\n");
    {
        printf("销毁L前:\n");
        L?printf("L存在\n"):printf("L不存在\n");
        DestroyList_L(&L);
        printf("销毁L后:\n");
        L?printf("L存在\n"):printf("L不存在\n");
        printf("\n");
    }
    printf("CreateList_HL测试\n");
    {
        FILE *fp;
        LinkList L;
        printf("头插法建立单链表L=");
        fp=fopen("TestData_HL.txt","r");
        CreateList_HL(fp,&L,5);
        fclose(fp);
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    printf("CreateList_TL测试\n");
    {
        FILE *fp;
        LinkList L;
        printf("尾插法建立单链表L=");
        fp=fopen("TestData_TL.txt","r");
        CreateList_TL(fp,&L,5);
        fclose(fp);
        ListTraverse_L(L,PrintElem);
        printf("\n\n");
    }
    
    //return 0; 
   system("pause");
}






















































