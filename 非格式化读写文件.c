#include <stdlib.h> 
#include <stdio.h>
#include<conio.h>
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
    
    if((fp=fopen("D:\\stu_list.txt","rt"))==NULL)
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1); 
    }
    
        
    for(i=0;i<NUM;i++)
    {
        fscanf(fp,"%d%s%d%f",&st[i].num,st[i].name,&st[i].age,&st[i].score);
    }
    fclose(fp);
    for(i=0;i<NUM;i++)
        printf("%d\t%s\t%d\t%f\t",st[i].num,st[i].name,st[i].age,st[i].score);
    
    
    
    if((fp=fopen("D:\\stu_list.txt","wt"))==NULL)
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1); 
    }
    
    fwrite(st,NUM,sizeof(struct student),fp);
    fclose(fp);
    if((fp=fopen("D:\\stu_list.txt","rt"))==NULL)
    {
        printf("不能打开文件，按任意键退出");
        getch();
        exit(1);
    }
    
    fread(st,NUM,sizeof(struct student),fp);
    fclose(fp);
    for(i=0;i<NUM;i++)
        printf("%d,%s,%d,%f\n",st[i].num,st[i].name,st[i].age,st[i].score);
    getch();
    system("pause");
}
