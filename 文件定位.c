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
    struct student st;
    if((fp=fopen("D:\\stu_list.dat","rb"))==NULL)
    {
        printf("���ܴ��ļ�����������˳�");
        getch();
        exit(1); 
    }
    printf("%d\n",ftell(fp));//���ָ���λ�� 
    //printf("%d\n",sizeof(struct student));
    

    fseek(fp,sizeof(struct student),0);//�ƶ�ָ�� 
    printf("%d\n",ftell(fp));
    
    fread(&st,1,sizeof(struct student),fp);//�����ݿ�
     
    fclose(fp);
    printf("%d,%s,%s,%f\n",st.num,st.name,st.age,st.score);
    getch(); 
    
    system("pause");
      
}
