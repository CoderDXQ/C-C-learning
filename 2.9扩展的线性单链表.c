#include <stdio.h>
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
void ClearList_E(ELinkList *L)
{
    Link p,q;
    p=(*L).head->next;
    while(p)
    {
        q=p->next;
        free(p);
        p=q;
    }
    (*L).head->next=NULL;
    (*L).tail=(*L).head;
    (*L).len=0;
    
}
void DestroyList_E(ELinkList *L)
{
    ClearList_E(L);
    free((*L).head);
    (*L).head=(*L).tail=NULL;
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
Status Remove_E(ELinkList *L,Link *q)
{
    Link p;
    if(!(*L).len)
    {
        *q=NULL;
        return ERROR;
    }
    *q=(*L).tail;
    p=(*L).head;
    while(p->next!=(*L).tail)
        p=p->next;
    p->next=NULL;
    (*L).tail=p;
    (*L).len--;
    return OK;
    
}
void InsBefore_E(ELinkList *L,Link *p,Link s)
{
    Link q;
    q=PriorPos_E(*L,*p);
    if(!q)
        q=(*L).head;
    s->next=*p;
    q->next=s;
    *p=s;
    (*L).len++;
      
}
void InsAfter_E(ELinkList *L,Link *p,Link s)
{
    if(*p==(*L).tail)
        (*L).tail=s;
    s->next=(*p)->next;
    (*p)->next=s;
    *p=s;
    (*L).len++;
      
}
void SetCurElem_E(Link p,LElemType_E e)
{
    p->data=e;
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
int ListLength_E(ELinkList L)
{
    return L.len;
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
PositionPtr LocateElem_E(ELinkList L,LElemType_E e,Status(Compare)(LElemType_E,LElemType_E))
{
    Link p=L.head->next;
    while(p && !(Compare(e,p->data)))
        p=p->next;
    return p;
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
Status ListDelete_L_E(ELinkList *L,int i,LElemType_E *e)
{
    Link p,q;
    if(i<1||i>(*L).len)
        return ERROR;
    LocatePos_E(*L,i-1,&p);
    DelFirst_E(L,p,&q);
    *e=q->data;
    free(q);
    q=NULL;
    return OK; 
}
Status CmpGreater(LElemType_E e,LElemType_E data);
void PrintElem(LElemType_E e);

Status CmpGreater(LElemType_E e,LElemType_E data)
{
    return data>e?TRUE:FALSE;
}
void PrintElem(LElemType_E e)
{
    printf("%d ",e);
}

int main()
{
    ELinkList L;
    Link p,q,s;           
    PositionPtr r;
    int i;
    LElemType_E e;
    
    printf("  InitList_E����\n");
    {
        printf("��ʼ����չ�ĵ�����\n");
        InitList_E(&L);
        printf("\n");
    }
    printf("  ListEmpty_E����\n");
    {
        ListEmpty_E(L)?printf("LΪ��\n"):printf("L��Ϊ��\n");
        printf("\n");
    }
    
    printf("  ListInsert_L_E����\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("��L�ĵ�%d��λ�ò���\"%d\"\n",i,2*i);
            ListInsert_L_E(&L,i,2*i);
        }   
        printf("\n");
    }
    printf("  ListTraverse����\n");
    {
        printf("L�е�Ԫ��Ϊ��L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  ListLength_E����\n");
    {
        i=ListLength_E(L);
        printf("L�ĳ���Ϊ%d\n",i);
        printf("\n");
    }
    printf("  ListDelete_L_E����\n");
    {
        ListDelete_L_E(&L,6,&e);
        printf("ɾ��L�е�6��Ԫ��\"%d\"\n",e);
        printf("L�е�Ԫ��Ϊ��L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    
    printf("  LocatePos_E����\n");
    {
        LocatePos_E(L,3,&p);
        printf("L�еĵ�3��Ԫ��\"%d\"�ĵ�ַΪOx%x\n",p->data,p);
        printf("\n");
    }
    printf("  PriorPos_E����\n");
    {
        r=PriorPos_E(L,p);
        printf("ָ��Pָ���Ԫ��\"%d\"��ǰ��Ԫ��Ϊ\"%d\"\n",p->data,r->data);
        printf("\n");
    }
    printf("  NextPos_E����\n");
    {
        r=NextPos_E(p);
        printf("ָ��Pָ���Ԫ��\"%d\"�ĺ��Ԫ��Ϊ\"%d\"\n",p->data,r->data);
        printf("\n");
    }
    printf("  LocateElem_E����\n");
    {
        r=LocateElem_E(L,7,CmpGreater);
        printf("L�е�һ��Ԫ��ֵ����7��Ԫ��\"%d\"�ĵ�ַΪOx%x\n",r->data,r);
        printf("\n");
    }
    printf("  MakeNode_E����\n");
    {
        printf("�������p\n");
        MakeNode_E(&p,101);
        printf("�������q\n");
        MakeNode_E(&q,202);
        printf("\n");
    }
    printf("  GetCurElem_E����\n");
    {
        e=GetCurElem_E(p);
        printf("���P��ֵΪ\"%d\"\n",e);
        e=GetCurElem_E(q);
        printf("���q��ֵΪ\"%d\"\n",e);
        printf("\n");
    }
    printf("  SetCurElem_E����\n");
    {
        printf("��888�滻p����е�ֵ\n");
        SetCurElem_E(p,888);
        printf("���q��ֵΪ\"%d\"\n",p->data); 
        printf("\n");
    }
    printf("  FreeNode_E����\n");
    {
        printf("���ٽ��pǰ��");
        p?printf("p����\n"):printf("p������\n");
        FreeNode_E(&p);
        printf("���ٽ��p��");
        p?printf("p����\n"):printf("p������\n");
        printf("\n");
    }
    printf("  Append_E����\n");
    {
        printf("��q������L���һ�����֮��\n");
        Append_E(&L,q);
        printf("L�е�Ԫ��Ϊ��L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  Remove_E����\n");
    {
        printf("ɾ��L�����һ����㣬��p����ɾ���Ľ��\n");
        Remove_E(&L,&p);
        printf("L�е�Ԫ��Ϊ:L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  InsFirst_E����\n");
    {
        printf("����ֵΪ303�Ľ��\n");
        MakeNode_E(&p,303);
        printf("��qָ��L�еĵ�4��Ԫ��\n");
        LocatePos_E(L,4,&q);
        printf("��p�����뵽��q��ͷ��������ĵ�һ�����֮ǰ\n");
        InsFirst_E(&L,q,p);
        printf("L�е�Ԫ��Ϊ��L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  DelFirst_E����\n");
    {
        printf("ɾ��L���Ե�4�����qΪͷ��������ĵ�һ�����\n");
        DelFirst_E(&L,q,&p);
        printf("��ǰL��ֵΪ��L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  GetHead_E����\n");
    {
        p=GetHead_E(L);
        printf("Lͷָ��Ϊp=L.head=Ox%x\n",p);
        printf("\n");
    }
    printf("  GetLast_E����\n");
    {
        q=GetLast_E(L);
        printf("L��βָ��Ϊq=L.tail=Ox%x\n",q);
        printf("\n");
    }
    printf("  InsBefore_E����\n");
    {
        printf("����ֵΪ404�Ľ��s\n");
        MakeNode_E(&s,404);
        printf("�����s���뵽β���q֮ǰ\n");
        InsBefore_E(&L,&q,s);
        printf("��ǰL��ֵΪ��L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  InsAfter_E����\n");
    {
        printf("����ֵΪ505�Ľ��s\n");
        MakeNode_E(&s,505);
        printf("�����s���뵽β���q֮��\n");
        InsAfter_E(&L,&p,s);
        printf("��ǰL��ֵΪ��L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  ClearList_E����\n");
    {
        printf("���Lǰ��");
        ListEmpty_E(L)?printf("LΪ��\n"):printf("L��Ϊ��\n"); 
        ClearList_E(&L);
        printf("���L��");
        ListEmpty_E(L)?printf("LΪ��\n"):printf("L��Ϊ��\n"); 
        printf("\n");
    }
    printf("  DestroyList_E����\n");
    {
        printf("����Lǰ��");
        L.head!=NULL && L.tail!=NULL?printf("L����\n"):printf("L������\n");
        DestroyList_E(&L);
        printf("����L��");
        L.head!=NULL && L.tail!=NULL?printf("L����\n"):printf("L������\n");
        printf("\n");
    }
    system("pause");
}

















