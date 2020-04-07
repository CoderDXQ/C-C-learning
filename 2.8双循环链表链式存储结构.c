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
    
    printf(" InitList_DuL����\n");
    {
        printf("��ʼ��˫ѭ������L\n");
        InitList_DuL(&L);    
        printf("\n");
    }
    printf(" ListEmpty_DuL����\n");
    {
        ListEmpty_DuL(L)?printf("LΪ��\n"):printf("L��Ϊ��\n");
        printf("\n");
    }
    printf(" ListInsert_DuL����\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("��L��%d��λ�ò���\"%d\"\n",i,2*i);
            ListInsert_DuL(L,i,2*i);
        }
        printf("\n");
    }
    printf(" ListTraverse_DuL_DuL����\n");
    {
        printf("L�е�Ԫ��ΪL=");
        ListTraverse_DuL(L,PrintElem);
        printf("\n\n");
    }
    printf(" ListLength_DuL����\n");
    {
        printf("L�ĳ���Ϊ%d\n",ListLength_DuL(L));
        printf("\n");
    }
    printf(" ListDelete_DuL����\n");
    {
        ListDelete_DuL(L,6,&e);
        printf("ɾ��L�еĵ�6��Ԫ��\"%d\"\n",e);
        printf("L�е�Ԫ��Ϊ��L=");
        ListTraverse_DuL(L,PrintElem); 
        printf("\n\n");
    }
    printf(" GetElem_DuL����\n");
    {
        GetElem_DuL(L,4,&e);
        printf("L�еĵ�4��λ�õ�Ԫ��Ϊ\"%d\"\n",e);
        printf("\n");
    }
    printf(" LocateElem_DuL����\n");
    {
        i=LocateElem_DuL(L,7,CmpGreater);
        printf("L�еĵ�һ��Ԫ��ֵ����\"7\"��Ԫ�ص�λ��Ϊ%d\n",i);
        printf("\n");
    }
    printf(" PriorElem_DuL����\n");
    {
        PriorElem_DuL(L,6,&e);
        printf("Ԫ��\"6\"��ǰ��Ϊ\"%d\"\n",e);
        printf("\n");
    }
    printf("NextElem_DuL����\n");
    {
        NextElem_DuL(L,6,&e);
        printf("Ԫ��\"6\"�ĺ��Ϊ\"%d\"\n",e);
        printf("\n");
    }
    printf(" GetElem_P����\n");
    {
        DuLinkList p;
        p=GetElemPtr_DuL(L,3);
        printf("�����3������ָ��ΪOx%x,���Ӧ��ֵΪ��\"%d\"\n",p,*p);
        printf("\n");
    }
    printf(" ClrearList_DuL����\n");
    {
        printf("���Lǰ��");
        ListEmpty_DuL(L)?printf("LΪ��\n"):printf("L��Ϊ��\n");
        ClearList_DuL(L); 
        printf("���L��");
        ListEmpty_DuL(L)?printf("LΪ��\n"):printf("L��Ϊ��\n");
        printf("\n");
    }
    printf(" DestroyList_DuL����\n");
    {
        printf("����Lǰ��");
        L?printf("L����\n"):printf("L������\n");
        DestroyList_DuL(&L); 
        printf("����L��");
        ListEmpty_DuL(L)?printf("L����\n"):printf("L������\n");
        printf("\n");
    }
    system("pause");
}

























