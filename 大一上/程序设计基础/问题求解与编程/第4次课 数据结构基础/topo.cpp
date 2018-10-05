#include <stdio.h>
#include <string.h>
const int MAXN = 1000;
int n, m, Relation[MAXN][MAXN]; //n������,m����ϵ,����Relation��Ź�ϵ
int c[MAXN]; //ȡ0ʱ��ʾ��㻹δ����������ȡ1ʱ��ʾ����չ��ϣ�ȡ-1��ʾ���ڱ���չ
int topo[MAXN], t; //����topo������õ������У�t�Ƿ������е�ָ��

bool dfs(int u)
{
	c[u] = -1;
	for(int v=0;v<n;v++)
		if(Relation[u][v])
		{
			if(c[v]<0) return false; //�������򻷣�ʧ���˳�
			else if(!c[v] && !dfs(v)) return false; //���v��û����չ����չv
		}
	c[u] = 1; //u�ѱ����������չ���
	topo[--t] = u; //��u��ӵ�����
	return true;
}

bool toposort()
{
	t = n;
	memset(c, 0 ,sizeof(c));
	for(int u = 0;u<n;u++)
		if(!c[u]) //�������������չ��㣬���u��û����չ������ô��չ��
			if(!dfs(u)) return false;  //�޺���˳��
	return true;
}

int main()
{
	scanf("%d%d", &n, &m);
	memset(Relation,0,sizeof(Relation));
	int u, v;
	for(int i=0;i<m;i++)
	{
		scanf("%d%d", &u, &v);
		Relation[u][v] = 1;
	}
	if(toposort())
		for(int i=0; i<n; i++)
			printf("%d\n", topo[i]);
	else
		printf("no path\n");

	return 0;
}