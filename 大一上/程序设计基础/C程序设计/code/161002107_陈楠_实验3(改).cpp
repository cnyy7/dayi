#include<stdio.h>
#define N 200 
int main()
{
	int i,j,k,n;
	printf("������༶������");
	scanf("%d",&n);
	printf("������ÿ���˵ĳɼ���"); 
	int scores[N];
	for(i=0;i<n;i++)
		scanf("%d",&scores[i]);
	printf("ѧ���ĳɼ�Ϊ:            ");
	for(i=0;i<n;i++)
		printf("%d\t",scores[i]);
	printf("\n");
	for(j=0;j<n-1;j++)
	{
		for(i=0;i<n-1-j;i++)
			if(scores[i]>scores[i+1])
				{
				k=scores[i];
				scores[i]=scores[i+1];
				scores[i+1]=k;
				}
	}
	printf("ѧ���ĳɼ���С��������Ϊ��"); 
	for(i=0;i<n;i++)
		printf("%d\t",scores[i]);
	return 0;
} 
