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
    
    printf("  InitList_E测试\n");
    {
        printf("初始化扩展的单链表\n");
        InitList_E(&L);
        printf("\n");
    }
    printf("  ListEmpty_E测试\n");
    {
        ListEmpty_E(L)?printf("L为空\n"):printf("L不为空\n");
        printf("\n");
    }
    
    printf("  ListInsert_L_E测试\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("在L的第%d个位置插入\"%d\"\n",i,2*i);
            ListInsert_L_E(&L,i,2*i);
        }   
        printf("\n");
    }
    printf("  ListTraverse测试\n");
    {
        printf("L中的元素为：L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  ListLength_E测试\n");
    {
        i=ListLength_E(L);
        printf("L的长度为%d\n",i);
        printf("\n");
    }
    printf("  ListDelete_L_E测试\n");
    {
        ListDelete_L_E(&L,6,&e);
        printf("删除L中第6个元素\"%d\"\n",e);
        printf("L中的元素为：L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    
    printf("  LocatePos_E测试\n");
    {
        LocatePos_E(L,3,&p);
        printf("L中的第3个元素\"%d\"的地址为Ox%x\n",p->data,p);
        printf("\n");
    }
    printf("  PriorPos_E测试\n");
    {
        r=PriorPos_E(L,p);
        printf("指针P指向的元素\"%d\"的前驱元素为\"%d\"\n",p->data,r->data);
        printf("\n");
    }
    printf("  NextPos_E测试\n");
    {
        r=NextPos_E(p);
        printf("指针P指向的元素\"%d\"的后继元素为\"%d\"\n",p->data,r->data);
        printf("\n");
    }
    printf("  LocateElem_E测试\n");
    {
        r=LocateElem_E(L,7,CmpGreater);
        printf("L中第一个元素值大于7的元素\"%d\"的地址为Ox%x\n",r->data,r);
        printf("\n");
    }
    printf("  MakeNode_E测试\n");
    {
        printf("创建结点p\n");
        MakeNode_E(&p,101);
        printf("创建结点q\n");
        MakeNode_E(&q,202);
        printf("\n");
    }
    printf("  GetCurElem_E测试\n");
    {
        e=GetCurElem_E(p);
        printf("结点P的值为\"%d\"\n",e);
        e=GetCurElem_E(q);
        printf("结点q的值为\"%d\"\n",e);
        printf("\n");
    }
    printf("  SetCurElem_E测试\n");
    {
        printf("用888替换p结点中的值\n");
        SetCurElem_E(p,888);
        printf("结点q的值为\"%d\"\n",p->data); 
        printf("\n");
    }
    printf("  FreeNode_E测试\n");
    {
        printf("销毁结点p前：");
        p?printf("p存在\n"):printf("p不存在\n");
        FreeNode_E(&p);
        printf("销毁结点p后：");
        p?printf("p存在\n"):printf("p不存在\n");
        printf("\n");
    }
    printf("  Append_E测试\n");
    {
        printf("将q结点插在L最后一个结点之后\n");
        Append_E(&L,q);
        printf("L中的元素为：L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  Remove_E测试\n");
    {
        printf("删除L中最后一个结点，用p接收删除的结点\n");
        Remove_E(&L,&p);
        printf("L中的元素为:L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  InsFirst_E测试\n");
    {
        printf("创建值为303的结点\n");
        MakeNode_E(&p,303);
        printf("令q指向L中的第4个元素\n");
        LocatePos_E(L,4,&q);
        printf("将p结点插入到以q怍头结点的链表的第一个结点之前\n");
        InsFirst_E(&L,q,p);
        printf("L中的元素为：L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  DelFirst_E测试\n");
    {
        printf("删除L中以第4个结点q为头结点的链表的第一个结点\n");
        DelFirst_E(&L,q,&p);
        printf("当前L的值为：L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  GetHead_E测试\n");
    {
        p=GetHead_E(L);
        printf("L头指针为p=L.head=Ox%x\n",p);
        printf("\n");
    }
    printf("  GetLast_E测试\n");
    {
        q=GetLast_E(L);
        printf("L的尾指针为q=L.tail=Ox%x\n",q);
        printf("\n");
    }
    printf("  InsBefore_E测试\n");
    {
        printf("创建值为404的结点s\n");
        MakeNode_E(&s,404);
        printf("将结点s插入到尾结点q之前\n");
        InsBefore_E(&L,&q,s);
        printf("当前L的值为：L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  InsAfter_E测试\n");
    {
        printf("创建值为505的结点s\n");
        MakeNode_E(&s,505);
        printf("将结点s插入到尾结点q之后\n");
        InsAfter_E(&L,&p,s);
        printf("当前L的值为：L=");
        ListTraverse_E(L,PrintElem);
        printf("\n\n");
    }
    printf("  ClearList_E测试\n");
    {
        printf("清空L前：");
        ListEmpty_E(L)?printf("L为空\n"):printf("L不为空\n"); 
        ClearList_E(&L);
        printf("清空L后：");
        ListEmpty_E(L)?printf("L为空\n"):printf("L不为空\n"); 
        printf("\n");
    }
    printf("  DestroyList_E测试\n");
    {
        printf("销毁L前：");
        L.head!=NULL && L.tail!=NULL?printf("L存在\n"):printf("L不存在\n");
        DestroyList_E(&L);
        printf("销毁L后：");
        L.head!=NULL && L.tail!=NULL?printf("L存在\n"):printf("L不存在\n");
        printf("\n");
    }
    system("pause");
}

















