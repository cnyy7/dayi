#include<stdio.h>
#define n 4
struct student{
	int num;
	char name[21];
	float math;
	float psy;
	float it;
	float aver;
};
struct student stu[4];
int main(void)
{
	void input(struct student stu[]);
	int compare(struct student stu[]);
	void print1(struct student *stu);
	void print2(struct student *stu);
	input(stu);
	compare(stu);
	printf("\n");
	print1(stu);
	printf("\n");
	print2(&stu[compare(stu)]);
	return 0;
}
void input(struct student stu[])
{
	int i=0;
	while(i<n)
	{
		printf("�������%d��ѧ����ѧ�ţ�",i+1);
		scanf("%d",&stu[i].num);
		getchar();
		printf("�������%d��ѧ����������",i+1);
		gets(stu[i].name);
		printf("�������%d��ѧ������ѧ�ɼ���",i+1);
		scanf("%f",&stu[i].math);
		printf("�������%d��ѧ��������ɼ���",i+1);
		scanf("%f",&stu[i].psy);
		printf("�������%d��ѧ���ļ�����ɼ���",i+1);
		scanf("%f",&stu[i].it);
		stu[i].aver=(stu[i].math+stu[i].it+stu[i].psy)/3;
		i++;
	}
}
int compare(struct student stu[])
{
	int i=0,j=0;
	while(i<n)
	{
		if(stu[i].aver>stu[j].aver)
			j=i;
		i++;
	}
	return j;
}
void print1(struct student *stu)
{
	int i;
	stu--;
	for(i=-1;i<n;i++,stu++)
	{
		printf(i==-1?"ѧ��\t����\t��ѧ\t����\t�����\tƽ���ɼ�\n":"%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",stu->num,stu->name,stu->math,stu->psy,stu->it,stu->aver);
	}
}
void print2(struct student *stu)
{
	printf("ƽ���ɼ���ߵ�ͬѧ��ѧ�š���������ѧ������������ɼ���ƽ���ɼ�Ϊ��\n");
	printf("%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\n",stu->num,stu->name,stu->math,stu->psy,stu->it,stu->aver);
}






























