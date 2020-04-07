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
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

#ifndef _MATH_H_
#define OVERFLOW -2
#define UNDERFLOW -3
#endif

#ifndef NULL
#define NULL((void*)0)
#endif

typedef int LElemType_Sq;
typedef int Status;

typedef struct
{
    LElemType_Sq *elem;
    int length;
    int listsize;
}SqList;

//函数声明 
Status InitList_Sq(SqList *L);

void ClearList_Sq(SqList *L);

void DestroyList_Sq(SqList *L);

Status ListEmpty_Sq(SqList *L);

int ListLength_Sq(SqList *L);

Status GetElem_Sq(SqList L,int i,LElemType_Sq *e);

int LocateElem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq));

Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e);

Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e);

Status ListInsert_Sq(SqList *l,int i,LElemType_Sq e);

Status ListDelete_Sq(SqList *l,int i,LElemType_Sq *e);

Status ListTraverse_Sq(SqList L,void(Visit)(LElemType_Sq));



//子函数 
Status InitList_Sq(SqList *L)  //初始化链表 
{
    (*L).elem=(LElemType_Sq*)malloc(LIST_INIT_SIZE*sizeof(LElemType_Sq));
    if(!(*L).elem) exit(OVERFLOW);
    (*L).length=0;
    (*L).listsize=LIST_INIT_SIZE;
    return OK;
}

void ClearList_Sq(SqList *L)
{
     (*L).length=0;   //清空链表 
}

void DestroyList_Sq(SqList *L)
{
    free((*L).elem);
    (*L).elem=NULL;    //释放内存后置空指针 
    (*L).length=0;
    (*L).listsize=0;
}

Status ListEmpty_Sq(SqList *L)
{
    return (*L).length==0?TRUE:FALSE;
}

int ListLength_Sq(SqList *L)
{
    return (*L).length;
}

Status GetElem_Sq(SqList L,int i,LElemType_Sq *e)
{
    if(i<1||i>L.length)
        return ERROR;
    else
        *e=L.elem[i-1];
    return OK;
}

int LocateElem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq))
{
    int i=1;
    while(i<=L.length && !Compare(e,L.elem[i-1]))
       ++i;
    if(i<L.length)
        return i;
    else
        return 0;
       
}

Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e)
{
    int i=1;
    if(L.elem[0]!=cur_e)
    {
        while(i<L.length && L.elem[i]!=cur_e)
           ++i;
        if(i<L.length)
        {
            *pre_e=L.elem[i-1];
            return OK;
        }       
    }
    return ERROR;
}

Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e)
{
    int i=0;
    while(i<L.length && L.elem[i]!=cur_e)
       ++i;
    if(i<L.length-1)
    {
        *next_e=L.elem[i+1];
        return OK;
    }
    return ERROR;
}

Status ListInsert_Sq(SqList *L,int i,LElemType_Sq e)
{
    LElemType_Sq *newbase;
    LElemType_Sq *p,*q;
    if(i<1 ||i>(*L).length+1)
        return ERROR;
    if((*L).length>=(*L).listsize)
    {
        newbase=(LElemType_Sq*)realloc((*L).elem,((*L).listsize+LISTINCREMENT)*sizeof(LElemType_Sq));
        if(!newbase)
            exit(OVERFLOW);
        (*L).elem=newbase;
        (*L).listsize+=LISTINCREMENT;
    }
    q=&(*L).elem[i-1];
    
    for(p=&(*L).elem[(*L).length-1];p>=q;--p)
        *(p+1)=*p;
    *q=e;
    (*L).length++;
    
    return OK;
}

Status ListDelete_Sq(SqList *L,int i,LElemType_Sq *e)
{
    int j;
    LElemType_Sq *p,*q;
    if(i<1||i>(*L).length)
        return ERROR;
    p=&(*L).elem[i-1];
    *e=*p;
    q=(*L).elem+(*L).length-1;
    
    for(++p;p<=q;++p)
        *(p-1)=*p;
    (*L).length--;
    
    return OK;
}                                                                                                                         

Status ListTraverse_Sq(SqList L,void(Visit)(LElemType_Sq))
{
    int i;
    for(i=0;i<L.length;i++)
        Visit(L.elem[i]);
    return OK;
}


//*****************************************
void MergeSqList_1(SqList La,SqList Lb,SqList *Lc);
void MergeSqList_2(SqList La,SqList Lb,SqList *Lc);
void PrintElem(LElemType_Sq e);



void MergeSqList_1(SqList La,SqList Lb,SqList *Lc)
{
    int La_len,Lb_len;
    int i,j,k;
    LElemType_Sq ai,bj;
    
    i=j=1;
    k=0;
    
    InitList_Sq(Lc);
    La_len=ListLength_Sq(&La);
    Lb_len=ListLength_Sq(&Lb);
    
    while(i<=La_len && j<=Lb_len)
    {
        GetElem_Sq(La,i,&ai);
        GetElem_Sq(Lb,j,&bj);
        
        if(ai<bj)
        {
            ListInsert_Sq(Lc,++k,ai);
            i++;
        }
        else
        {
            ListInsert_Sq(Lc,++k,bj);
            j++; 
        }
    }
    while(i<=La_len)
    {
        GetElem_Sq(La,i++,&ai);
        ListInsert_Sq(Lc,++k,ai);
    }
    
    while(j<=Lb_len)
    {
        GetElem_Sq(Lb,j++,&bj);
        ListInsert_Sq(Lc,++k,bj);
    }
    
    
}


void MergeSqList_2(SqList La,SqList Lb,SqList *Lc)
{
    LElemType_Sq *pa,*pb,*pc;
    LElemType_Sq *pa_last,*pb_last;
    
    pa=La.elem;
    pb=Lb.elem;
    
    (*Lc).listsize=(*Lc).length=La.length+Lb.length;
    pc=(*Lc).elem=(LElemType_Sq *)malloc((*Lc).listsize*sizeof(LElemType_Sq));
    if(!pc)
        exit(OVERFLOW);
        
    pa_last=La.elem+La.length-1;
    pb_last=Lb.elem+Lb.length-1;
    
    while(pa<=pa_last&&pb<=pb_last)
    {
        if(*pa<=*pb)
            *pc++=*pa++;
        else
            *pc++=*pb++;
    }
    while(pa<=pa_last)
        *pc++=*pa++;
    while(pb<=pb_last)
        *pc++=*pb++;
}

void PrintElem(LElemType_Sq e)
{
    printf("%d ",e);
}

int main()
{
    SqList La,Lb,Lc1,Lc2;
    LElemType_Sq a[4]={3,5,8,11};
    LElemType_Sq b[7]={2,6,8,9,11,15,20};
    int i;
    
    InitList_Sq(&La);
    for(i=1;i<=4;i++)
        ListInsert_Sq(&La,i,a[i-1]);
    InitList_Sq(&Lb);
    for(i=1;i<=7;i++)
        ListInsert_Sq(&Lb,i,b[i-1]);
    
    printf("La=");
    ListTraverse_Sq(La,PrintElem);
    printf("\n");
    printf("Lb=");
    ListTraverse_Sq(Lb,PrintElem);
    printf("\n\n");
    
    
    MergeSqList_1(La,Lb,&Lc1);
    printf("合并La和Lb为Lc1=");
    ListTraverse_Sq(Lc1,PrintElem);
    printf("\n\n");    
    MergeSqList_2(La,Lb,&Lc2);
    printf("合并La和Lb为Lc2=");
    ListTraverse_Sq(Lc2,PrintElem);
    printf("\n\n");  

    system("pause");
}







