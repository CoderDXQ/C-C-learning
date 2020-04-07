#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 1000
#define TRUE  1
#define FALSE 0
#define YES   1
#define NO    0
#define OK    1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS 0
#define INFEASIBLE -1
#define OVERFLOW -2
#define UNDERFLOW -3

#ifndef NULL
#define NULL((void*)0)
#endif


typedef int Status;
typedef int SLinkList;
typedef int LElemType_S;
typedef struct
{
    LElemType_S data;
    int cur;
}Component[MAXSIZE];

Component SPACE;

void InitSpace_SL();
int Malloc_SL();
void Free_SL(int k);
int InitList_SL(SLinkList *H);
Status ClearList_SL(SLinkList H);
void DestroyList_SL(SLinkList *H);
Status ListEmpty_SL(SLinkList H);
int ListLength_SL(SLinkList H);
Status GetElem_SL(SLinkList H,int i,LElemType_S *e);
int LocateElem_SL(SLinkList H,LElemType_S e);
Status PriorElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_e);
Status NextElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_eR);
Status ListInsert_SL(SLinkList H,int i,LElemType_S e);
Status ListDelete_SL(SLinkList H,int i,LElemType_S *e);
Status ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S));
void PrintElem(LElemType_S e);



void PrintElem(LElemType_S e)
{
    printf("%d ",e);
}


void InitSpace_SL()
{
   int i;
   for(i=0;i<MAXSIZE-1;i++)
       SPACE[i].cur=i+1;
   SPACE[MAXSIZE-1].cur=0; 
}
int Malloc_SL()
{
    int i;
    i=SPACE[0].cur;
    if(SPACE[0].cur)
    {
        SPACE[0].cur=SPACE[i].cur;
        return i;
    }
    else
        return 0;
}
void Free_SL(int k)
{
    SPACE[k].cur=SPACE[0].cur;
    SPACE[0].cur=k;
}
int InitList_SL(SLinkList *H)
{
    *H=Malloc_SL();
    if(!(*H))
        exit(OVERFLOW);
    SPACE[*H].cur=0;
    return OK;
}
Status ClearList_SL(SLinkList H)
{
    int p,q;
    if(!H)
        return ERROR;
    p=SPACE[H].cur;
    while(p)
    {
        SPACE[H].cur=SPACE[p].cur;
        Free_SL(p);
        p=SPACE[H].cur;
    }
    return OK;
}
void DestroyList_SL(SLinkList *H)
{
    ClearList_SL(*H);
    Free_SL(*H);
    *H=0;
}
Status ListEmpty_SL(SLinkList H)
{
    if(H && !SPACE[H].cur)
        return TRUE;
    else
        return FALSE;
}
int ListLength_SL(SLinkList H)
{
    int count;
    int p;
    if(!H)
        exit(OVERFLOW);
    count=0;
    p=SPACE[H].cur;
    while(p)
    {
        count++;
        p=SPACE[p].cur;
    }
    return count;
}
Status GetElem_SL(SLinkList H,int i,LElemType_S *e)
{
    int count,p;
    if(!H || i<1 ||i>MAXSIZE-2)
        return ERROR;
    count=0;
    p=SPACE[H].cur;
    while(p)
    {
        count++;
        if(count==i)
        {
            *e=SPACE[p].data;
            return OK;
        }
        p=SPACE[p].cur;
    }
}
int LocateElem_SL(SLinkList H,LElemType_S e)
{
    int k,count;
    count=1;
    if(H && SPACE[H].cur)
    {
        k=SPACE[H].cur;
        while(k && SPACE[k].data!=e)
        {
            count++;
            k=SPACE[k].cur;
        }
        if(k)
            return count;
    }
    return 0;
}
Status PriorElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *pre_e)
{
    int p,q;
    if(H)
    {
        p=SPACE[H].cur;
        if(p && SPACE[p].data!=cur_e)
        {
            q=SPACE[p].cur;
            while(q && SPACE[q].data!=cur_e)
            {
                p=q;
                q=SPACE[q].cur;
            }
            if(q)
            {
                *pre_e=SPACE[p].data;
                return OK;
            }
        }
    }
    return ERROR;
}
Status NextElem_SL(SLinkList H,LElemType_S cur_e,LElemType_S *next_e)
{
    int p;
    if(H)
    {
        p=SPACE[H].cur;
        while(p && SPACE[p].data!=cur_e)
            p=SPACE[p].cur;
        if(p && SPACE[p].cur)
        {
            p=SPACE[p].cur;
            *next_e=SPACE[p].data;
            return OK;
        }
    }
    return ERROR;
}
Status ListInsert_SL(SLinkList H,int i,LElemType_S e)
{
    int count,k,p;
    if(!H)
        return ERROR;
    if(i>0)
    {
        count=0;
        k=H;
        while(k &&count<i-1)
        {
            count++;
            k=SPACE[k].cur;
        }
        if(k)
        {
            p=Malloc_SL();
            if(!p)
                return ERROR;
            SPACE[p].data=e;
            SPACE[p].cur=SPACE[k].cur;
            SPACE[k].cur=p;
            return OK;
        }
    }
    return ERROR;
}
Status ListDelete_SL(SLinkList H,int i,LElemType_S *e)
{
    int count,k,p;
    if(!H)
        return ERROR;
    if(i>0)
    {
        count=0;
        k=H;
        while(k &&count<i-1)
        {
            count++;
            k=SPACE[k].cur;
        }
        if(k && SPACE[k].cur)
        {
            p=SPACE[k].cur;
            *e=SPACE[p].data;
            SPACE[k].cur=SPACE[p].cur;
            Free_SL(p);
        
            return OK;
        }
    }
    return ERROR;   
}
Status ListTraverse_SL(SLinkList H,void(Visit)(LElemType_S))
{
    int p;
    if(!H)
        return ERROR;
    p=SPACE[H].cur;
    while(p)
    {
        Visit(SPACE[p].data);
        p=SPACE[p].cur;
    }
    return OK;
}




int main()
{
    SLinkList H;
    LElemType_S e;
    int i;
    
    printf(" InitSpace_SL测试\n");
    {
        printf("初始化静态链表的备用空间\n");
        InitSpace_SL(); 
        printf("\n");
    }
    printf(" Malloc_SL&&InitList_SL测试\n");
    {
        printf("初始化静态链表H，用malloc——SL申请空间\n");
        InitList_SL(&H); 
        printf("\n");
    }
    printf(" ListEmpty_SL测试\n");
    {
        ListEmpty_SL(H)?printf("H为空\n"):printf("H不为空\n");
        printf("\n");
    }
    printf(" ListInsert_SL测试\n");
    {
        for(i=1;i<=6;i++)
        {
            printf("在H第%d个位置插入\"%d\"\n",i,2*i);
            ListInsert_SL(H,i,2*i);
        }
        printf("\n");
    }
    printf(" ListTraverse_SL测试\n");
    {
        printf("H中的元素为：H=");
        ListTraverse_SL(H,PrintElem); 
        printf("\n\n");
    }
    printf(" ListLength_SL测试\n");
    {
        printf("H的长度为%d\n",ListLength_SL(H));
        printf("\n");
    }
    printf(" Free_SL&&ListDelete_SL测试\n");
    {
        ListDelete_SL(H,6,&e);
        printf("删除H中的第6个元素\"%d\"，用Free——SL释放空间\n",e);
        printf("H的元素为：H="); 
        ListTraverse_SL(H,PrintElem); 
        printf("\n\n");
    }
    printf(" GetElem_SL测试\n");
    {
        GetElem_SL(H,4,&e);
        printf("H中第四个位置的元素为\"%d\"\n",e);
        printf("\n");
    }
    printf(" LocateELem_SL测试\n");
    {
        printf("元素\"8\"在H中的位序为%d\n",LocateElem_SL(H,8));
        printf("\n");
    }
    printf(" PriorElem_SL测试\n");
    {
        PriorElem_SL(H,6,&e);
        printf("元素\"6\"的前驱为\"%d\"\n",e);
        printf("\n");
    }
    printf(" NextElem_SL测试\n");
    {
        NextElem_SL(H,6,&e);
        printf("元素\"6\"的后继为\"%d\"\n",e);
        printf("\n");
    }
    printf(" ClearList_SL测试\n");
    {
        printf("清空H前：");
        ListEmpty_SL(H)?printf("H为空\n"):printf("H不为空\n");
        ClearList_SL(H);
        printf("清空H后：");
        ListEmpty_SL(H)?printf("H为空\n"):printf("H不为空\n");
        ClearList_SL(H);
        printf("\n");
    }
    printf(" DestroyList_SL测试\n");
    {
        printf("销毁H前：");
        H?printf("H存在\n"):printf("H不存在\n");
        DestroyList_SL(&H); 
        printf("销毁H后：");
        H?printf("H存在\n"):printf("H不存在\n");
        printf("\n");
    }
    system("pause");
}




















