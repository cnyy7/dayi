#include<stdio.h>
//#include<string.h>
const int MAXN = 100; //������k��ֵ
int a[MAXN]; //�������Ҫ������е�y
int main()
{
	int k;
	while(scanf("%d",&k)==1)
	{
		int count=0;
		for(int y=k+1;y<=2*k;y++)
			if((k*y)%(y-k)==0)
			{
				a[count++] = y;
			}
		printf("%d\n",count);
		for(int i=0;i<count;i++)
			printf("1/%d = 1/%d + 1/%d\n", k, (k*a[i])/(a[i]-k), a[i]);
	}
	return 0;
}
