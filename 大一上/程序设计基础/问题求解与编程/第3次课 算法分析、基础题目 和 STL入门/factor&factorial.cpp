#include<stdio.h>
#include<string.h>

//�����ж���n����̫��
int is_prime(int n)
{
	for(int i = 2;i*i<=n;i++)
		if(n%i==0) return 0;
	return 1;
}

int prime[100], count=0; //������

int main()
{
	int n, p[100]; //n�͸���������ָ��
	
	for(int i=2;i<=100;i++) 
	{

		if(is_prime(i)) prime[count++] = i;
	} //����������

	while(scanf("%d",&n)==1)
	{
		memset(p,0,sizeof(p));
		int maxp = 0;
		for(int i=2;i<=n;i++)
		{
			int m = i;  //����ֱ����i����Ϊm��仯
			for(int j=0;j<count;j++)
				while(m % prime[j]==0)  //��������prime[j]�����ۼ�p[j]
				{
					p[j]++;
					m /= prime[j];
					if(j>maxp)              //������������±�
						maxp = j;
				}
		}
		printf("%d! = ", n);
		//ֻѭ����������ӵ��±괦
		for(int i=0;i<=maxp;i++)
			printf("%d ", p[i]);
		printf("\n");
	}
  
	return 0;
}