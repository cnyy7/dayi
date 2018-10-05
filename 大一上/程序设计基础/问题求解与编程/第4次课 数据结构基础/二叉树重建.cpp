#include <stdio.h>
#include <string.h>
const int MAXN = 50;

// ����Ϊn     s1 ǰ��     s2 ����   �������s3
void build(int n, char * s1, char * s2, char * s3)
{
	if(n<=0) return;
	int p = strchr(s2, s1[0]) - s2;  //�ҵ����ڵ�����������е�λ��
	build(p, s1+1, s2, s3);          //�ݹ��������ĺ������
	build(n-p-1, s1+p+1, s2+p+1, s3+p);  //�ݹ��������ĺ������
	s3[n-1] = s1[0];   //�Ѹ��ڵ���ӵ����
}

int main()
{
	char s1[MAXN], s2[MAXN], s3[MAXN];
	while(scanf("%s%s",s1,s2) == 2)
	{
		int n = strlen(s1);
		build(n,s1,s2,s3);
		s3[n] = '\0';
		printf("%s\n", s3);

	}
	return 0;
}