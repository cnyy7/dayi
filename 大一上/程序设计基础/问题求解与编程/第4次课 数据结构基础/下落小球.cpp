#include<stdio.h>
#include<string.h>
const int MAXD = 20;
int s[1<<MAXD];  //���ڵ���� 2^MAXD - 1

int main()
{
	int D, I;	
	while(scanf("%d%d", &D, &I) == 2)
	{
		memset(s,0,sizeof(s));  //���س�ʼȫ0����ʾ�ر�
		int k, n = (1<<D)-1;    //k��ʾ���䵽�Ľڵ�Ŀ����±�
		for(int i=0;i<I;i++)    //������I��С��
		{
			k = 1;
			while(1)
			{
				s[k] = !s[k];
				k = s[k] ? 2*k : 2*k+1;  //���ݿ���ѡ����������
				if(k > n) break;  //�䵽���⣬����
			}
		}
		printf("%d\n", k/2); //����ǰҶ�ӽڵ���
	}

	return 0;
}