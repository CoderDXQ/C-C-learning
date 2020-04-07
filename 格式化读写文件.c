#include <stdlib.h> 
#include <stdio.h>
#include <conio.h>
struct student
{
    int num;
    char name[20];
    int age;
    float score;
};
#define NUM 5
main()
{
    FILE *fp;
    int i;
    struct student st[NUM];
    for(i=0;i<NUM;i++)
    {
        printf("请输入学号 姓名 年龄 成绩：\n");
        scanf("%d%s%d%f",&st[i].num,st[i].name,&st[i].age,&st[i].score);
    }
    if((fp=fopen("D:\\stu_list.txt","wt"))==NULL)//打开文件，如果没有就创建文件 
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1); 
    }
    for(i=0;i<NUM;i++)
        fprintf(fp,"%d\t%s\t%d\t%f\t",st[i].num,st[i].name,st[i].age,st[i].score);
    //fclose(fp);
    /*if((fp=fopen("D:\\stu_list.txt","rt"))==NULL)
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1);
    }*/
    rewind(fp);
    for(i=0;i<NUM;i++)
    {
        fscanf(fp,"%d%s%d%f",&st[i].num,st[i].name,&st[i].age,&st[i].score);
    }
    //fclose(fp);
    for(i=0;i<NUM;i++)
        printf("%d,%s,%d,%f\n",st[i].num,st[i].name,st[i].age,st[i].score);
    system("pause");
}
