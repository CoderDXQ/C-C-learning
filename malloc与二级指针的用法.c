#include <stdio.h>
#include <stdlib.h>
struct student
{
    int num;
    char name[20];
    float score;
       };
       //结构体的定义后面有分号
void read(struct student **p,int *n); //*代表指针变量，在这里不是运算符 
void sort(struct student *p,int n); 
void write(struct student *p,int n); 
void swap(struct student *p1,struct student *p2);  
//必须有的函数声明     
main()
{
    struct student *p; //指针就是数组，数组就是指针 
    int n;
    read(&p,&n);//传地址 
    sort(p,n);
    write(p,n); 
    free(p);    
    system("pause");
}

void read(struct student **p,int *n)//*p，n是指针变量，存的是地址 
{
    int i;
    puts("请输入学生数量");
    scanf("%d",n);//n就是地址，所以不需要取址符 
    *p=malloc(*n*sizeof(struct student));//*p存的是地址 
    for(i=0;i<*n;i++)
    {
        puts("请输入同学的学号、姓名、成绩：");
        scanf("%d%s%f",&(*p)[i].num,(*p)[i].name,&(*p)[i].score);
    }//(*p)可以认为是数组名 
}
void sort(struct student *p,int n)
{
    int i,j;
    for(i=0;i<n-1;i++)
        for(j=0;j<n-i-1;j++)
            if(p[j].score<p[j+1].score)
                swap(&p[j],&p[j+1]);
}
void write(struct student *p,int n)
{
     int i;
     for(i=0;i<n;i++)
         printf("学号：%d，姓名：%s,成绩：%.1f\n",p[i].num,p[i].name,p[i].score);
     
}

void swap(struct student *p1,struct student *p2)
{
     struct student t;
     t=*p1;
     *p1=*p2;
     *p2=t;
}//交换的是值，而不是地址,交换地址没有用 
