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

#define LIST_INIT_SIZE 100
#define LISTINCREMENT 10

typedef int LElemType_Sq;


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


Status CmpGreater(LElemType_Sq e,LElemType_Sq data);
void PrintElem(LElemType_Sq e);



int main()
{
    SqList L;
    int i;
    LElemType_Sq e;
    
    printf("InitList_Sq测试\n");
    {
        printf("初始化顺序链表\n");
        InitList_Sq(&L);
        printf("\n");
    }

    
    printf("ListEmpty_Sq测试...\n");
    {
        ListEmpty_Sq(&L)?printf("L为空\n"):printf("L不为空\n");
        printf("\n");
    }

    
    printf("ListInsert_Sq测试\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("在L的第%d个位置插入\"%d\"...\n",i,2*i);
            ListInsert_Sq(&L,i,2*i);
        }
        printf("\n");
    }

    
    printf("ListTraverse_Sq测试\n");
    {
        printf("L中的元素为：L=");
        ListTraverse_Sq(L,PrintElem);
        printf("\n");
    }

    
    printf("ListLength_Sq测试\n");
    {
        i=ListLength_Sq(&L);
        printf("L的长度为%d\n",i);
        printf("\n");
    }
    
    printf("ListDelete_Sq测试\n");
    {
        ListDelete_Sq(&L,6,&e);
        printf("删除L中的第6个元素\"%d\"...\n",e);
        printf("L中的元素为：L=");
        ListTraverse_Sq(L,PrintElem);
        printf("\n\n");  
    }
 
    
    printf("GetElem测试\n");
    {
        GetElem_Sq(&L,4,&e);
        printf("L中第四个元素为\"%d\"\n",e);
        printf("\n");
    }

    
    
    printf("LocateElem测试\n");
    {
        i=LocateElem_Sq(L,7,CmpGreater);
        printf("L中第一个元素大于\"7\"的元素的位置为%d\n",i);
        printf("\n");
    }

    printf("PriorElem_Sq测试\n");
    {
        PriorElem_Sq(L,6,&e);
        printf("元素\"6\"的前驱为\"%d\"\n",e);
        printf("\n");
    }

    
    printf("NextElem_Sq测试\n");
    {
        NextElem_Sq(L,6,&e);
        printf("元素\"6\"的后继为\"%d\"\n",e);
        printf("\n");
    }

    
    printf("ClearList_Sq测试\n");
    {
        printf("清空L前：");
        ListEmpty_Sq(&L)?printf("L为空\n"):printf("L不为空\n");
        ClearList_Sq(&L);
        printf("清空L后：");
        ListEmpty_Sq(&L)?printf("L为空\n"):printf("L不为空\n");
        printf("\n");
    }

    
    printf("DestroyList_Sq测试\n");
    {
        printf("销毁L前：");
        L.elem ? printf("L存在\n"):printf("L不存在\n");
        DestroyList_Sq(&L);
        printf("销毁L后：");
        L.elem ? printf("L存在\n"):printf("L不存在\n");
        printf("\n"); 
    }
  
    //return 0;  
    
    system("pause");
}

Status CmpGreater(LElemType_Sq e,LElemType_Sq data)
{
    return data>e ? TRUE:FALSE;
}



void PrintElem(LElemType_Sq e)
{
    printf("%d",e);
}










