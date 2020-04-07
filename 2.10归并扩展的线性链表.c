#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>

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
typedef int LElemType_E;


typedef struct ELNode
{
    LElemType_E data;
    struct ELNode *next;
}ELNode;
typedef ELNode* Link;
typedef ELNode* PositionPtr;
typedef struct
{
    Link head,tail;
    int len;
}ELinkList;

Status MakeNode_E(Link *p,LElemType_E e);
void FreeNode_E(Link *p);
Status InitList_E(ELinkList *L);
void ClearList_E(ELinkList *L);
void DestroyList_E(ELinkList *L);
void InsFirst_E(ELinkList *L,Link h,Link s);
Status DelFirst_E(ELinkList *L,Link h,Link *q);
void Append_E(ELinkList *L,Link s);
Status Remove_E(ELinkList *L,Link *q);
void InsBefore_E(ELinkList *L,Link *p,Link s);
void InsAfter_E(ELinkList *L,Link *p,Link s);
void SetCurElem_E(Link p,LElemType_E e);
LElemType_E GetCurElem_E(Link p);
Status ListEmpty_E(ELinkList L);
int ListLength_E(ELinkList L);
PositionPtr GetHead_E(ELinkList L);
PositionPtr GetLast_E(ELinkList L);
PositionPtr PriorPos_E(ELinkList L,Link p);
PositionPtr NextPos_E(Link p);
Status LocatePos_E(ELinkList L,int i,Link *p);
PositionPtr LocateElem_E(ELinkList L,LElemType_E e,Status(Compare)(LElemType_E,LElemType_E));
Status ListTraverse_E(ELinkList L,void(Visit)(LElemType_E));
Status ListInsert_L_E(ELinkList *L,int i,LElemType_E);
Status ListDelete_L_E(ELinkList *L,int i,LElemType_E *e);

//￥￥￥￥￥￥￥￥￥￥￥￥￥￥
Status MergeEList_L(ELinkList La,ELinkList Lb,ELinkList *Lc,int(Compare)(LElemType_E c1,LElemType_E c2));
int Cmp(LElemType_E c1,LElemType_E c2);
Status CreateList_ascend(FILE *fp,ELinkList *L,int count);


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
Status MakeNode_E(Link *p,LElemType_E e)
{
    *p=(Link)malloc(sizeof(ELNode));
    if(!(*p))
        exit(OVERFLOW);
    (*p)->data=e;
    (*p)->next=NULL;
    return OK;   
      
}
void FreeNode_E(Link *p)
{
    free(*p);
    *p=NULL;
       
}
Status InitList_E(ELinkList *L)
{
    Link p;
    p=(Link)malloc(sizeof(ELNode));
    if(!p)
        exit(OVERFLOW);
    p->next=NULL;
    
    (*L).head=(*L).tail=p;
    (*L).len=0;
    return OK;
   
}
void InsFirst_E(ELinkList *L,Link h,Link s)
{
    s->next=h->next;
    h->next=s;
    
    if(h==(*L).tail)
        (*L).tail=h->next;
    (*L).len++;
       
}
Status DelFirst_E(ELinkList *L,Link h,Link *q)
{
    *q=h->next;
    if(*q)
    {
        h->next=(*q)->next;
        if(!h->next)
            (*L).tail=h;
        (*L).len--;
        return OK;
    } 
    return ERROR;
}
void Append_E(ELinkList *L,Link s)
{
    int count=0;
    (*L).tail->next=s;
    while(s)
    {
        (*L).tail=s;
        s=s->next;
        count++;
    }
    (*L).len+=count;
      
}
LElemType_E GetCurElem_E(Link p)
{
    return p->data;
}
Status ListEmpty_E(ELinkList L)
{
    if(L.len)
        return FALSE;
    else
        return TRUE;
}
PositionPtr GetHead_E(ELinkList L)
{
    return L.head;
}
PositionPtr GetLast_E(ELinkList L)
{
    return L.tail;
}
PositionPtr PriorPos_E(ELinkList L,Link p)
{
    Link q;
    q=L.head->next;
    if(q==p)
        return NULL;
    else
    {
        while(q->next!=p)
            q=q->next;
        return q;
    }
}
PositionPtr NextPos_E(Link p)
{
    return p->next;
}
Status LocatePos_E(ELinkList L,int i,Link *p)
{
    int count=0;
    *p=L.head;
    if(i<0||i>L.len)
        return ERROR;
    while(count<i)
    {
        count++;
        *p=(*p)->next;
    }
    return OK;
    
}

Status ListTraverse_E(ELinkList L,void(Visit)(LElemType_E))
{
    Link p;
    int j;
    p=L.head->next;
    for(j=1;j<=L.len;j++)
    {
        Visit(p->data);
        p=p->next;
    }
    return OK;
}

Status ListInsert_L_E(ELinkList *L,int i,LElemType_E e)
{
    Link h,s;
    if(!LocatePos_E(*L,i-1,&h))
        return ERROR;
    if(!MakeNode_E(&s,e))
        return ERROR;
    InsFirst_E(L,h,s);
    return OK;
}

Status CmpGreater(LElemType_E e,LElemType_E data);
void PrintElem(LElemType_E e);

void PrintElem(LElemType_E e)
{
    printf("%d ",e);
}
//&&&&&&&&&&&&&&&&&&&&&&&
Status MergeEList_L(ELinkList La,ELinkList Lb,ELinkList *Lc,int(Compare)(LElemType_E c1,LElemType_E c2))
{
    Link ha,hb,pa,pb,q;
    LElemType_E c1,c2;
    if(!InitList_E(Lc))
        return ERROR;
    ha=GetHead_E(La);
    hb=GetHead_E(Lb);
    pa=NextPos_E(ha);
    pb=NextPos_E(hb);
    while(!ListEmpty_E(La)&&!ListEmpty_E(Lb))
    {
        c1=GetCurElem_E(pa);
        c2=GetCurElem_E(pb);
        if(Compare(c1,c2)<=0)
        {
            DelFirst_E(&La,ha,&q);
            InsFirst_E(Lc,(*Lc).tail,q);
            pa=NextPos_E(ha);
        }
        else
        {
            DelFirst_E(&Lb,hb,&q);
            InsFirst_E(Lc,(*Lc).tail,q);
            pa=NextPos_E(hb);
        }
    } 
    if(!ListEmpty_E(La))
        Append_E(Lc,pa);
    else
        Append_E(Lc,pb);
    
    printf("%d",ListEmpty_E(La));   
    FreeNode_E(&ha);
    FreeNode_E(&hb);
    
    return OK;
} 
int Cmp(LElemType_E c1,LElemType_E c2)
{
    return c1=c2;
} 
Status CreateList_ascend(FILE *fp,ELinkList *L,int count)
{
    int i;
    LElemType_E e;
    InitList_E(L);//必须要先创建链表才能进行接下来的操作 
    if(!L)
        return ERROR;
    for(i=1;i<=count;i++)
    {
        Scanf(fp,"%d",&e);
        ListInsert_L_E(L,i,e);
    }
    return OK;
} 

int main()
{
    FILE *fp;
    ELinkList La,Lb,Lc;
    int m,n;
    m=6;
    n=7;
    
    printf("作为示例，La的长度设定为%d，Lb的长度设定为%d,创建La和Lb\n",m,n);
    fp=fopen("TestData_La.txt","r");
    CreateList_ascend(fp,&La,m);
    fclose(fp);
    fp=fopen("TestData_Lb.txt","r");
    CreateList_ascend(fp,&Lb,n);
    fclose(fp);
    
    printf("La=");
    ListTraverse_E(La,PrintElem);
    printf("\n");
    printf("Lb=");
    ListTraverse_E(Lb,PrintElem);
    printf("\n\n");
    
    MergeEList_L(La,Lb,&Lc,Cmp);
    printf("合并La和Lb为Lc=");
    ListTraverse_E(Lc,PrintElem);
    printf("\n\n");    
    
    system("pause");

}



















