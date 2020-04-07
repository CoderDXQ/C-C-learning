#include <stdio.h>
#include <stdlib.h>
struct student
{
    int num;
    char name[20];
    float score;
       };//结构体的定义后面有分号
void read(struct student *p,int n); 
void sort(struct student *p,int n); 
void write(struct student *p,int n); 
void swap(struct student *p,int n); 
       
main()
{
    struct student *p;
    int n;
    puts("请输入学生数量");
    scanf("%d",&n);
    p=malloc(n*sizeof(struct student));
    read(p,n);
    sort(p,n);
    write(p,n);
    free(p,n);    
    system("pause");
}

void read(struct student *p,int n)
{
    int i;
    for(i=0;i<n;i++)
    {
        puts("请输入同学的学号、姓名、成绩：");
        scanf("%d%s%f",&p[i].num,p[i].name,&p[i].score);
    }
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
void swap(struct student *p,int n)
{
     struct student t;
     t=*p1;
     *p1=*p2;
     *p2=t;
}
