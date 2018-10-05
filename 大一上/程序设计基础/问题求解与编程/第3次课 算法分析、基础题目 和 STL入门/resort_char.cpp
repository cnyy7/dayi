#include <stdio.h>
#include <stdlib.h>   //qsort()������ʹ��qsort���������Լ�дһ���ȽϺ���
#include <string.h>

//�ַ��ȽϺ�����ʹ��qsort��׼д��
int cmp_char(const void * _a, const void * _b)  
{
	char * a = (char *)_a;
	char * b = (char *)_b;
	return *a - *b;
}

//�ַ����ȽϺ���
int cmp_string(const void * _a, const void * _b)
{
	char * a = (char *)_a;
	char * b = (char *)_b;
	return strcmp(a,b);
}

char word[1000][10], sorted[1000][10];

int main()
{
	int n=0;

	for(;;)
	{
		scanf("%s",word[n]); // scanf_s("%s", word[n], 10);
		if(word[n][0]=='*') break; //����������־��ֹѭ��
		n++;
	}

	qsort(word, n, sizeof(word[0]), cmp_string);  //���ֵ��е����е�������

	for(int i=0;i<n;i++)
	{
		strcpy(sorted[i], word[i]);
		qsort(sorted[i], strlen(sorted[i]), sizeof(char), cmp_char); //���ֵ䱸���е�ÿ��������ĸ����
	}

	char s[10];
	while(scanf("%s", s)==1)  // scanf_s("%s", s, 10) == 1
	{
		qsort(s, strlen(s), sizeof(char), cmp_char); //�����뵥����ĸ����
		int found = 0;
		for(i=0;i<n;i++)
		{
			if(strcmp(sorted[i],s)==0)
			{
				found = 1;
				printf("%s ", word[i]);  //���ԭʼ����
			}
		}
		if(!found) printf("-1");
		printf("\n");
	}
	return 0;
}