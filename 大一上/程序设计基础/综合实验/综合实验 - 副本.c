#include<stdio.h>
#include<stdbool.h>
#include<ctype.h>
#include<string.h>
#include<conio.h> 
#include<stdlib.h> 
#define M 6 	 																//�궨�����γ����� 
#define N 37	 																//�궨�����ѧ������ 
void menu(void);																//����˵����� 
void test(void);																//��������Ƿ�������ɼ����� 
void student_input(void);														//����¼��ɼ�����												
void information_save(void);													//���屣��ɼ�����
void student_change(void);														//�����޸ĳɼ����� 
void student_del(void);															//����ɾ���ɼ����� 
void student_aver1(void);														//������ĳ���˵ļ��ſγ̵�ƽ���ɼ����� 
void student_sort(void);														//�����������˵�ƽ���ɼ��������� 
void class_aver2(void);															//������ĳ�ſγ̵�ƽ���ɼ�����
void class_sort2(void);															//������ÿ�ſγ̵�ƽ���ɼ��������� 
void student_sort3(void);														//�����ĳ�ſγ������˵ĳɼ������� 
void student_rank(void);														//������ĳһ�����ڰ༶�����κ��� 
void information_print(void);													//��������ɼ�����
void program_out(void);															//�����˳�ϵͳ���� 
bool Y_N_test2(void);
int cmp1(const void *a,const void *b);					
int cmp2(const void *a,const void *b);
int cmp3(const void *a,const void *b);
int cmp4(const void *a,const void *b);											//����qsort����������� 
int cmp5(const void *a,const void *b);
int cmp6(const void *a,const void *b);
int cmp7(const void *a,const void *b);
int cmp8(const void *a,const void *b);	
int cmp9(const void *a,const void *b);										
bool full=false;																//�洢�Ƿ��Ѿ�������ɼ� 
struct classes{																	//����γ̽ṹ�� 
	int number;																	//�γ���� 
	float avers;																//�ÿγ�ƽ���ɼ�
	char class_name[17];														//�γ����� 		
};
struct student{																	//����ѧ���ṹ�� 
	char num[11];																//ѧ�� 
	char name[17];																//���� 
	float scores[M];															//���ųɼ� 
	float aver;																	//��ѧ����ƽ���ɼ� 
};
struct classes mean[M];															//����γ̽ṹ������ 
struct student stu[N];															//����ѧ���ṹ������ 
struct student *p=stu;
														
int n;																			//����ȫ�ֱ��������û������ѧ������ 
int m;																			//����ȫ�ֱ��������û�����Ŀγ����� 
FILE *fp;																		//�����ļ�ָ�� 


int main(void)
{

	printf( "                  	 ----------------------------\n"
			"                  	 ��ӭ����༶ѧϰ�ɼ�����ϵͳ\n"
			"                  	 ----------------------------\n\n"
			"           	---��Ȩ���У��������16-1��  ���  161002107---\n\n"); 
	menu();
	return 0;
} 																
void menu(void)
{
	int t;
	char ch,mh[10];																//�����ַ����ַ������鴢���û���������� 
	printf(	"------------------------------------\n" 
			" 1)	¼��ɼ�\n"
			" 2)	����ɼ�\n"
			" 3)	�޸ĳɼ�\n"
			" 4)	ɾ���ɼ�\n"
			" 5)	��ĳ���˵ļ��ſγ̵�ƽ���ɼ�\n"
			" 6)	�������˵�ƽ���ɼ�������\n"
			" 7)	��ĳ�ſγ̵�ƽ���ɼ�\n"
			" 8)	��ÿ�ſγ̵�ƽ���ɼ�������\n"
			" 9)	��ĳһ�����ڰ༶������\n"
			" 0)	��ĳ�ſγ������˵ĳɼ�����\n"
			" T)	�˳�\n"
			"------------------------------------\n"
			"��ѡ���������һ�д��������:");
//	if(isnumber())
//		getchar();
	scanf("%s",mh);									
	ch=mh[0];																	//������Ϊ�ַ��Ͳ�ֱ�жϵ�һ���ַ�������switch����ʱ�����ַ���ɵ���ѭ�� 
//	getchar();
	switch(ch) 
	{ 
		case '1':student_input();break; 
		case '2':information_save();break; 
		case '3':student_change();break; 
		case '4':student_del();break; 
		case '5':student_aver1();break;											//ͨ�������ָ�����ִ����һ������ 
		case '6':student_sort();break;
		case '7':class_aver2();break;
		case '8':class_sort2();break;
		case '9':student_rank();break; 
		case '0':student_sort3();break;
		case 't':
		case 'T':program_out();break;
		default:printf("�������!����������\n");menu();break; 
	}	 
}
void student_input(void)
{
	int i,j;
	char ch;
	if(!full)																	//�ж��Ƿ��Ѿ�¼����ɼ� 
	{
		printf("������༶����(1-37)��γ�����(1-6)��");
		scanf("%d%d",&n,&m);													//�û�����༶������γ����� 
		printf("�밴˳������γ����֣�\n");
		for(i=0;i<m;i++)
		{
			scanf("%s",mean[i].class_name);
		}
	}
	else
	{
		printf("�Ѿ�¼������� �Ƿ�����¼�룿(YΪȷ��������Ϊ���ϣ�:");
		getchar();																//���ܻس��� 
		scanf("%c",&ch);
		if(ch=='y'||ch=='Y')
		{
			full=false;
			student_input();
		}
		else
		{
			menu();
		}
	} 
		
	for(i=0;i<n;i++)															//ѭ������ÿ��ѧ������Ϣ		
	{	
		stu[i].aver=0;															//��ʼ��ÿ��ѧ����ƽ���ɼ� 
		printf("�������%d��ѧ����ѧ�ţ�",i+1);
		scanf("%s",stu[i].num);
		getchar();																//���ܻس��� 
		printf("�������%d��ѧ����������",i+1);
		gets(stu[i].name);
		for(j=0;j<m;j++)														//ѭ������ÿ��ѧ���ĳɼ� 
		{
			printf("�������%d��ѧ��%s�ɼ���",i+1,mean[j].class_name);
			scanf("%f",&stu[i].scores[j]);
			stu[i].aver+=stu[i].scores[j];	
		}	
		stu[i].aver/=m;															//����ÿ��ѧ����ƽ���ɼ� 
	}
	printf("\n               --------------¼�����--------------\n\n");
	full=true;																	//���Ƿ�������ɼ�Ϊ�� 
	printf("\n-------�밴���������......\n");
	getch();																	//�޻��Ե�ȡһ���ַ��������������� 
	system("CLS");																//���� 
	menu(); 																	//�ص��˵� 
}
void information_save(void)
{
	test();																		//�����Ƿ�������ɼ� 
	int i,j;	
	char filename[17];
	qsort(stu,n,sizeof(stu[0]),cmp1);											//�Խṹ�尴�ܳɼ��ܴ�С�������� 
	printf("������Ҫ������ļ������֣�");
	scanf("%s",filename);
	if((fp=fopen(filename,"w"))==NULL)											//�ж��ļ��ܷ�� 
	{
		printf("�޷��򿪴��ļ���\n");
		menu();
	}
	fprintf(fp,"����\tѧ��\t����");
	for(j=0;j<m;j++)
	{
		fprintf(fp,"\t%s",mean[j].class_name);
	}
	fprintf(fp,"\t\tƽ���ɼ�\n");
	for(j=0;j<m+5;j++)
	{
		fprintf(fp,"--------");
	}
	fputc(10,fp);
	for(i=0;i<n;i++)															//ѭ��д��ɼ� 
	{
		fprintf(fp,"%3d\t%s\t%s\t",i+1,stu[i].num,stu[i].name);					//���ø�ʽ���ķ�ʽд������ 
		for(j=0;j<m;j++)
		{
			fprintf(fp,"%.1f\t",stu[i].scores[j]);
		} 
		fprintf(fp,"\t%.1f\n",stu[i].aver);
	}
	fclose(fp);	
	printf("\n               --------------����ɹ�--------------\n\n"
		   "\n-------�밴���������......\n");						
	getch();																	//�޻��Ե�ȡһ���ַ��������������� 
	system("CLS");																//���� 
	menu();
	
}
void test(void)
{
	while(!full)																//�ж��Ƿ�������ɼ� 
	{
		system("CLS");		
		printf("\n\n                      -----û�����ݣ���¼��ɼ�����б�����-----\n\n\n");
		menu();
	}
	return;
}
bool Y_N_test2(void)
{
	char ch;
	getchar();																	//���ܻس��� 
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
		return true;
	else
	{
		return false;
	}
}
void student_aver1(void)
{
	test();
	int i;
	char k[11];
	bool t=true;
	while(t)
	{
		printf("������Ҫ��ѯ��ѧ����ѧ�ţ�");
		scanf("%s",k);
		for(i=0;i<n;i++)
		{
			if(strcmp(stu[i].num,k)==0)											//�Ƚ��û�����ĵ�ѧ��������ѧ���Ƿ���ͬ 
			{
				printf("\n��ѧ��Ŀǰ����ϢΪ��\nѧ��\t����\tƽ���ɼ�\n---------------------------\n%s\t%s\t%.1f\n",stu[i].num,stu[i].name,stu[i].aver);
				break;
			}
		}
		if(i==n)																//û����ͬѧ��ʱ���� 
		{
			printf("--�޴�ѧ��!\n");
		} 
		printf("�Ƿ������ѯ?(YΪȷ��������Ϊ���ϣ�:");
		t=Y_N_test2();	
	}
	system("CLS");
	menu();
}
void student_rank(void)
{
	test();
	int i;
	char k[11];
	bool t=true;
	qsort(stu,n,sizeof(stu[0]),cmp1);
	while(t)
	{
		printf("������Ҫ��ѯ��ѧ����ѧ�ţ�");
		scanf("%s",k);
		for(i=0;i<n;i++)
		{
			if(strcmp(stu[i].num,k)==0)
			{
				printf("\n��ѧ��������Ϊ��%d\n",i+1);
				break;
			}
		}
		if(i==n)
		{
			printf("--�޴�ѧ��!\n");
		 } 
		printf("\n�Ƿ������ѯ?(YΪȷ��������Ϊ���ϣ�:");
		t=Y_N_test2();
	}
	system("CLS");
	menu();
}
void program_out(void)
{
	char ch; 
	printf("ȷ���˳�ϵͳ��(YΪȷ��������Ϊ����):"); 
	getchar();																	//���ܻس��� 
	scanf("%c",&ch);
	if(ch=='y'||ch=='Y')
	{
		printf( "\n\n\n                  	 ----------------------------\n"
				"                  	 ��лʹ�ð༶ѧϰ�ɼ�����ϵͳ\n"
				"                  	 ----------------------------\n\n"
				"           	---��Ȩ���У��������16-1��  ���  161002107---\n\n");
		exit(EXIT_SUCCESS);
	} 
	else
	{
		system("CLS");		
		menu();
    }
}
void information_print(void)
{
	int i,j;
	printf("\n���������£�\n");
	printf("\n\n����\tѧ��\t����");
	for(j=0;j<m;j++)
	{
		printf("\t%s",mean[j].class_name);
	}
	printf("\t\tƽ���ɼ�\n");
	for(j=0;j<m+6;j++)
	{
		printf("--------");
	}
	for(i=0;i<n;i++)															//ѭ����ʽ��ӡѧ����Ϣ 
	{
		printf("\n%3d\t%s\t%s\t",i+1,stu[i].num,stu[i].name);
		for(j=0;j<m;j++)
			printf("%.1f\t",stu[i].scores[j]); 
		printf("\t%.1f",stu[i].aver);
	}
	printf("\n\n\n");
	return ;
}
void student_change(void)
{
	test();
	int i,j;
	char ch,k[11];
	bool t=true;
	system("CLS");																//���� 
	printf( "\n                    -------------------------\n"
			"                    ��ӭ����ѧԱ��Ϣ�޸�ϵͳ!\n"
			"                    -------------------------\n\n"); 
	while(t)
	{
		printf("������Ҫ�޸ĵ�ѧ����ѧ�ţ�");
		scanf("%s",k);
		for(i=0;i<n;i++)
		{
			if(strcmp(stu[i].num,k)==0)											//�Ƚ��û�����ĵ�ѧ��������ѧ���Ƿ���ͬ 
			{
				printf("\n��ѧ��Ŀǰ����ϢΪ��\nѧ��\t����\t");
				for(j=0;j<m;j++)
				{
					printf("%s\t",mean[j].class_name);
				}
				putchar(10);
				for(j=0;j<m+2;j++)
				{
					printf("--------");
				}
				printf("\n%s\t%s\t",stu[i].num,stu[i].name);
				for(j=0;j<m;j++)
					printf("%.1f\t",stu[i].scores[j]); 
				printf("\nȷ���޸�?(YΪȷ��������Ϊ����):");
				getchar();														//���ܻس��� 
				scanf("%c",&ch);
				if(ch=='y'||ch=='Y')
				{
					stu[i].aver=0;
					printf("�������µ���Ϣ��\n�������µ�ѧ�ţ�");
					scanf("%s",stu[i].num);
					printf("�������µ�������");
					getchar();													//���ܻس��� 
					gets(stu[i].name);
					printf("�������µĿγ̳ɼ���");
					for(j=0;j<m;j++)
					{
						scanf("%f",&stu[i].scores[j]);
						stu[i].aver+=stu[i].scores[j];
					}
					stu[i].aver/=m;												//�����µ�ƽ��ֵ 
					printf("\n      --------------�޸����--------------\n\n");
					break;
				}
				else
					break;
			}
		}
		if(i==n)
		{
			printf("--�޴�ѧ��!\n"); 
		} 
		printf("�Ƿ�����޸�?(YΪȷ��������Ϊ���ϣ�:");
		t=Y_N_test2();
	}
	printf( "\n\n                    ----------------------------\n"
			"                    ��лʹ��ѧԱ��Ϣ�޸�ϵͳ!\n"
			"                    ----------------------------\n"); 
	printf("\n-------�밴���������.....\n");
	getch(); 																	//�޻��Ե�ȡһ���ַ��������������� 
	system("CLS");																//���� 	
	menu();		
}
void student_del(void)
{
	test();	
	int i,j;
	char ch,k[11];
	bool t=true;
	system("CLS");																//���� 	
	printf( "\n                    -------------------------\n"
			"                    ��ӭ����ѧԱ��Ϣɾ��ϵͳ!\n"
			"                    -------------------------\n\n"); 
	while(t)
	{
		printf("������Ҫɾ����ѧ����ѧ�ţ�");
		scanf("%s",k);
		for(i=0;i<n;i++)
		{
			if(strcmp(stu[i].num,k)==0)											//�Ƚ��û�����ĵ�ѧ��������ѧ���Ƿ���ͬ 		
			{
				printf("\n��ѧ��Ŀǰ����ϢΪ��\nѧ��\t����\t");
				for(j=0;j<m;j++)
				{
					printf("%s\t",mean[j].class_name);
				}
				putchar(10);
				for(j=0;j<m+2;j++)
				{
					printf("--------");
				}
				printf("\n%s\t%s\t",stu[i].num,stu[i].name);
				for(j=0;j<m;j++)
					printf("%.1f\t",stu[i].scores[j]); 
				printf("%.1f\n",stu[i].aver);
				printf("ȷ��ɾ��?(YΪȷ��������Ϊ����):");
				getchar();														//���ܻس��� 
				scanf("%c",&ch);
				if(ch=='y'||ch=='Y')
				{
					for(j=i;j<n;j++) 
						stu[j]=stu[j+1]; 
					printf("\n      --------------ɾ�����--------------\n\n");
					n--;
					goto loop;													//ɾ����ɺ�����loop������ִ�� 
				}																//����ɾ�����һ������ʱ����޴�ѧ�� 
				else
					break;
			}
		}
		if(i==n)
		{
			printf("--�޴�ѧ��!\n");
		} 
		loop:printf("\n�Ƿ����ɾ��?(YΪȷ��������Ϊ���ϣ�:");
		t=Y_N_test2();
	}
	printf( "\n               -------------------------\n"
			"               ��лʹ��ѧԱ��Ϣɾ��ϵͳ!\n"
			"               -------------------------\n");
	printf("\n-------�밴���������......\n");
	getch(); 																	//�޻��Ե�ȡһ���ַ��������������� 
	system("CLS");																//���� 	
	menu();	
 } 
void student_sort(void)
{
	test();
	qsort(stu,n,sizeof(stu[0]),cmp1);
	information_print();
	printf("\n-------�밴���������......\n");
	getch();																	//�޻��Ե�ȡһ���ַ��������������� 
	system("CLS");																//���� 	
	menu();
}

void class_sort2(void)
{
	test();	
	int i,j;
	for(i=0;i<m;i++)															//��ʼ���γ���� 
		mean[i].number=i+1;
	for(i=0;i<m;i++)
		mean[i].avers=0;														//��ʼ���γ�ƽ���ɼ� 
	for(j=0;j<m;j++)															//ѭ����ʽ����γ̵�ƽ���ɼ� 
	{
		for(i=0;i<n;i++)
		{
			mean[j].avers+=stu[i].scores[j];
		}
		mean[j].avers/=n;
	}
	qsort(mean,m,sizeof(mean[0]),cmp2);											//�Կγ̽ṹ��������� 
	printf("���������£�\n\n");
	for(i=-1;i<m;i++)															//ѭ�������� 
	{
		printf(i==-1?"\n����\t�γ�\tƽ���ɼ�\n------------------------\n":"%3d\t%s\t  %4.1f\n",i+1,mean[i].class_name,mean[i].avers);
	}
	printf("\n\n");
	printf("\n-------�밴���������.....\n");
	qsort(mean,m,sizeof(mean[0]),cmp9);											//���س�ʼ˳�� 
	getch();																	//�޻��Ե�ȡһ���ַ��������������� 
	system("CLS");																//���� 	
	menu();
}
void student_sort3(void)
{
	test();
	char k[17];
	int i,j,abc;
	bool t=true;
	for(i=0;i<m;i++)															//��ʼ���γ���� 
		mean[i].number=i+1;
	while(t)
	{
		printf("�����������ſγ̶������˵ĳɼ�����");
//		getchar();																//���ܻس��� 
		scanf("%s",k);
	for(i=0;i<m;i++)
	{
		if(strcmp(mean[i].class_name,k)==0)											//�Ƚ��û�����ĵ�ѧ��������ѧ���Ƿ���ͬ 		
		{
			abc=mean[i].number;
			switch(abc)																//switchҪ��ѯ�ڼ��ſ� 
			{
				case 1:qsort(stu,n,sizeof(stu[0]),cmp3);break;
				case 2:qsort(stu,n,sizeof(stu[0]),cmp4);break;
				case 3:qsort(stu,n,sizeof(stu[0]),cmp5);break;
				case 4:qsort(stu,n,sizeof(stu[0]),cmp6);break;
				case 5:qsort(stu,n,sizeof(stu[0]),cmp7);break;
				case 6:qsort(stu,n,sizeof(stu[0]),cmp8);break;
				default:printf("�޴˿γ̣�\n");goto laap;break;
			}
			information_print();
			printf("\n");
			break;
		}	
	}
	if(i==m)
	{
		printf("�޴˿γ̣�\n");
	} 
		laap:printf("\n�Ƿ������ѯ?(YΪȷ��������Ϊ���ϣ�:");
		t=Y_N_test2();
	}
	system("CLS");
	menu();
}
int cmp1(const void *a,const void *b) 
{ 
	return (*(struct student *)a).aver<(*(struct student *)b).aver ? 1 : -1; 
}
int cmp2(const void *a,const void *b)
{
	return (*(struct classes *)a).avers<(*(struct classes *)b).avers ? 1 : -1;
} 
int cmp3(const void *a,const void *b)
{
	return (*(struct student *)a).scores[0]<(*(struct student *)b).scores[0] ? 1 : -1;
} 
int cmp4(const void *a,const void *b)
{
	return (*(struct student *)a).scores[1]<(*(struct student *)b).scores[1] ? 1 : -1;					//����qsort�����������
} 																										//���Ӵ�С 
int cmp5(const void *a,const void *b)																	//�������� 
{
	return (*(struct student *)a).scores[2]<(*(struct student *)b).scores[2] ? 1 : -1;
} 
int cmp6(const void *a,const void *b)
{
	return (*(struct student *)a).scores[3]<(*(struct student *)b).scores[3] ? 1 : -1;
} 
int cmp7(const void *a,const void *b)
{
	return (*(struct student *)a).scores[4]<(*(struct student *)b).scores[4] ? 1 : -1;
} 
int cmp8(const void *a,const void *b)
{
	return (*(struct student *)a).scores[5]<(*(struct student *)b).scores[5] ? 1 : -1;
} 
int cmp9(const void *a,const void *b)
{
	return (*(struct classes *)a).number>(*(struct classes *)b).number ? 1 : -1;
} 
void class_aver2(void)
{
	test();	
	int i,j;
	char k[17];
	bool t=true;	
	for(i=0;i<m;i++)																//��ʼ���γ���� 
		mean[i].number=i+1;
	for(i=0;i<m;i++)
		mean[i].avers=0;															//��ʼ���γ�ƽ���ɼ� 
	for(j=0;j<m;j++)																//ѭ����ʽ����γ̵�ƽ���ɼ� 
	{
		for(i=0;i<n;i++)
		{
			mean[j].avers+=stu[i].scores[j];
		}
		mean[j].avers/=n;
	}
	while(t)
	{
		printf("\n������Ҫ�����ſγ̵�ƽ���ɼ���");
		scanf("%s",k);
		for(i=0;i<m;i++)
		{
			if(strcmp(k,mean[i].class_name)==0)
			{
				printf("\n%s��ƽ���ɼ�Ϊ��%.1f\n",mean[i].class_name,mean[i].avers);
				break;
			}
		}
		if(i==m)
			printf("�޴˿γ̡�\n");
		printf("\n�Ƿ������ѯ?(YΪȷ��������Ϊ���ϣ�:");
		t=Y_N_test2();
	}
	system("CLS");
	menu();
}
