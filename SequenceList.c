#ifndef SEQUENCELIST_C
#define SEQUENCELIST_C
//
//#include "SequenceList.h"
//

#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include <stdlib.h>


#define TRUE        1
#define FALSE       0
#define YES         1
#define NO          0
#define OK          1
#define ERROR       0
#define SUCCESS     1
#define UNSUCCESS   0
#define INFEASIBLE -1

#ifndef _MATH_H_
#define OVERFLOW -2
#define UNDERFLOW -3
#endif

#ifndef NULL
#define NULL((void*)0)
#endif  

typedef int Status;





//宏定义
#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

//顺序表类型定义
#ifndef LELEMTYPE_SQ
#define LELEMTYPE_SQ
typedef int LElemType_Sq;
#endif

typedef struct
{
    LElemType_Sq *elem;
    int length;
    int listsize;
}SqList;



Status InitList_Sq(SqList *L);

void ClearList_Sq(SqList *L);

void DestroyList_Sq(SqList *L);

Status ListEmpty_Sq(SqList *L);

int ListLength_Sq(SqList *L);

Status GetElem_Sq(SqList *L,int i,LElemType_Sq *e);

int LocateElem_Sq(SqList L,LElemType_Sq e,Status(Compare)(LElemType_Sq,LElemType_Sq));

Status PriorElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *pre_e);

Status NextElem_Sq(SqList L,LElemType_Sq cur_e,LElemType_Sq *next_e);

Status ListInsert_Sq(SqList *l,int i,LElemType_Sq e);

Status ListDelete_Sq(SqList *l,int i,LElemType_Sq *e);

Status ListTraverse_Sq(SqList L,void(Visit)(LElemType_Sq));





//
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

Status GetElem_Sq(SqList *L,int i,LElemType_Sq *e)
{
    if(i<1||i>(*L).length)
        return ERROR;
    else
        *e=(*L).elem[i-1];
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




#endif










