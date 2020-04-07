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

typedef int Status;
typedef int LElemType_DC;

typedef struct DuLNode
{
    LElemType_DC data;
    struct DuLNode *prior;
    struct DuLNode *next;
}DuLNode;
typedef DuLNode* DuLinkList;

Status InitList_DuL(DuLinkList *L);
Status ClearList_DuL(DuLinkList L);
void DestroyList_DuL(DuLinkList *L);
Status ListEmpty_DuL(DuLinkList L);
int ListLength_DuL(DuLinkList L);
Status GetElem_DuL(DuLinkList L,int i,LElemType_DC *e);
int LocateElem_DuL(DuLinkList L,LElemType_DC e,Status(Compare)(LElemType_DC,LElemType_DC));
Status PriorElem_DuL(DuLinkList L,LElemType_DC cur_e,LElemType_DC *pre_e);
Status NextElem_DuL(DuLinkList L,LElemType_DC cur_e,LElemType_DC *next_e);
DuLinkList GetElemPtr_DuL(DuLinkList L,int i);
Status ListInsert_DuL(DuLinkList L,int i,LElemType_DC e);
Status ListDelete_DuL(DuLinkList L,int i,LElemType_DC *e);
void ListTraverse_DuL(DuLinkList L,void(Visit)(LElemType_DC));



Status InitList_DuL(DuLinkList *L)
{
    *L=(DuLinkList)malloc(sizeof(DuLNode));
    if(!(*L))
        exit(OVERFLOW);
    (*L)->next=(*L)->prior=*L;
    return OK;
}
Status ClearList_DuL(DuLinkList L)
{
    DuLinkList p,q;
    p=L->next;
    while(p!=L)
    {
        q=p->next;
        free(p);
        p=q;
    }
    L->next=L->prior=L;
    return OK;
    
}
void DestroyList_DuL(DuLinkList *L)
{
    ClearList_DuL(*L);
    free(*L);
    *L=NULL;
}
Status ListEmpty_DuL(DuLinkList L)
{
    if(L && L->next==L && L->prior==L)
        return TRUE;
    else
        return FALSE;
}
int ListLength_DuL(DuLinkList L)
{
    DuLinkList p;
    int count;
    if(L)
    {
        count=0;
        p=L;
        while(p->next!=L)
        {
            count++;
            p=p->next;
        }
    }
    return count;
}
Status GetElem_DuL(DuLinkList L,int i,LElemType_DC *e)
{
    DuLinkList p;
    int count;
    if(L)
    {
        count=1;
        p=L->next;
        while(p!=L && count<i)
        {
            count++;
            p=p->next;
        }
        if(p!=L)
        {
            *e=p->data;
            return OK;
        }
    }
    return ERROR;
}
int LocateElem_DuL(DuLinkList L,LElemType_DC e,Status(Compare)(LElemType_DC,LElemType_DC))
{
    DuLinkList p;
    int count;
    if(L)
    {
        count=1;
        p=L->next;
        while(p!=L && !Compare(e,p->data))
        {
            count++;
            p=p->next;
        }
        if(p!=L)
            return count;
    }
    return 0;
}
Status PriorElem_DuL(DuLinkList L,LElemType_DC cur_e,LElemType_DC *pre_e)
{
    DuLinkList p;
    if(L)
    {
        p=L->next;
        while(p!=L &&p->data!=cur_e)
            p=p->next;
        if(p!=L && p->prior->data)
        {
            *pre_e=p->prior->data;
            return OK;
        }
    }
    return ERROR;
}
Status NextElem_DuL(DuLinkList L,LElemType_DC cur_e,LElemType_DC *next_e)
{
    DuLinkList p;
    if(L)
    {
        p=L->next;
        while(p!=L &&p->data!=cur_e)
            p=p->next;
        if(p!=L && p->next!=L)
        {
            *next_e=p->next->data;
            return OK;
        }
    }
    return ERROR;
}
DuLinkList GetElemPtr_DuL(DuLinkList L,int i)
{
    int count;
    DuLinkList p;
    if(L && i>0)
    {
        count=1;
        p=L->next;
        while(p!=L && count<i)
        {
            count++;
            p=p->next;
        }
        if(p!=L)
            return p;
    }
    return NULL; 
}
Status ListInsert_DuL(DuLinkList L,int i,LElemType_DC e)
{
    DuLinkList p,s;
    if(i<1 ||i>ListLength_DuL(L)+1)
        return ERROR;
    p=GetElemPtr_DuL(L,i);
    if(!p)
        p=L;
    s=(DuLinkList)malloc(sizeof(DuLNode));
    if(!s)
        exit(OVERFLOW);
    s->data=e;
    
    s->prior=p->prior;
    p->prior->next=s;
    s->next=p;
    p->prior=s;
    return OK;    
}
Status ListDelete_DuL(DuLinkList L,int i,LElemType_DC *e)
{
    DuLinkList p;
    if(!(p=GetElemPtr_DuL(L,i)))
        return ERROR;
    *e=p->data;
    p->prior->next=p->next;
    p->next->prior=p->prior;
    free(p);
    p=NULL;
    return OK;
}
void ListTraverse_DuL(DuLinkList L,void(Visit)(LElemType_DC))
{
    DuLinkList p;
    p=L->next;    
    while(p!=L)
    {
        Visit(p->data);
        p=p->next;
    }
}


Status CmpGreater(LElemType_DC e,LElemType_DC data);
void PrintElem(LElemType_DC e);


Status CmpGreater(LElemType_DC e,LElemType_DC data)
{
    return data>e?TRUE:FALSE;
}
void PrintElem(LElemType_DC e)
{
    printf("%d ",e);
}


int main()
{
    DuLinkList L;
    int i;
    LElemType_DC e;
    
    printf(" InitList_DuL测试\n");
    {
        printf("初始化双循环链表L\n");
        InitList_DuL(&L);    
        printf("\n");
    }
    printf(" ListEmpty_DuL测试\n");
    {
        ListEmpty_DuL(L)?printf("L为空\n"):printf("L不为空\n");
        printf("\n");
    }
    printf(" ListInsert_DuL测试\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("在L第%d个位置插入\"%d\"\n",i,2*i);
            ListInsert_DuL(L,i,2*i);
        }
        printf("\n");
    }
    printf(" ListTraverse_DuL_DuL测试\n");
    {
        printf("L中的元素为L=");
        ListTraverse_DuL(L,PrintElem);
        printf("\n\n");
    }
    printf(" ListLength_DuL测试\n");
    {
        printf("L的长度为%d\n",ListLength_DuL(L));
        printf("\n");
    }
    printf(" ListDelete_DuL测试\n");
    {
        ListDelete_DuL(L,6,&e);
        printf("删除L中的第6个元素\"%d\"\n",e);
        printf("L中的元素为：L=");
        ListTraverse_DuL(L,PrintElem); 
        printf("\n\n");
    }
    printf(" GetElem_DuL测试\n");
    {
        GetElem_DuL(L,4,&e);
        printf("L中的第4个位置的元素为\"%d\"\n",e);
        printf("\n");
    }
    printf(" LocateElem_DuL测试\n");
    {
        i=LocateElem_DuL(L,7,CmpGreater);
        printf("L中的第一个元素值大于\"7\"的元素的位置为%d\n",i);
        printf("\n");
    }
    printf(" PriorElem_DuL测试\n");
    {
        PriorElem_DuL(L,6,&e);
        printf("元素\"6\"的前驱为\"%d\"\n",e);
        printf("\n");
    }
    printf("NextElem_DuL测试\n");
    {
        NextElem_DuL(L,6,&e);
        printf("元素\"6\"的后继为\"%d\"\n",e);
        printf("\n");
    }
    printf(" GetElem_P测试\n");
    {
        DuLinkList p;
        p=GetElemPtr_DuL(L,3);
        printf("链表第3个结点的指针为Ox%x,其对应的值为：\"%d\"\n",p,*p);
        printf("\n");
    }
    printf(" ClrearList_DuL测试\n");
    {
        printf("清空L前：");
        ListEmpty_DuL(L)?printf("L为空\n"):printf("L不为空\n");
        ClearList_DuL(L); 
        printf("清空L后：");
        ListEmpty_DuL(L)?printf("L为空\n"):printf("L不为空\n");
        printf("\n");
    }
    printf(" DestroyList_DuL测试\n");
    {
        printf("销毁L前：");
        L?printf("L存在\n"):printf("L不存在\n");
        DestroyList_DuL(&L); 
        printf("销毁L后：");
        ListEmpty_DuL(L)?printf("L存在\n"):printf("L不存在\n");
        printf("\n");
    }
    system("pause");
}

























