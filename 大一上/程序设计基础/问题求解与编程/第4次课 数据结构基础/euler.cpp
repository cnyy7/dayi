#include<stdio.h>
#include<string.h>
const int MAXN = 1000;
int n, m, G[MAXN][MAXN], vis[MAXN][MAXN];

void euler(int u)
{
	for(int v=0;v<n;v++)
		if(G[u][v] && !vis[u][v])
		{
			vis[u][v] = vis[v][u] = 1; //����ͼ
			euler(v);
			printf("%d %d\n", u, v); // ��ӡ��˳��������ģ����ȴ�ӡ�ı�ʵ����Ӧ����󾭹�
		}
}

int main()
{
	FILE * file;
	file = fopen("euler.in", "rb");
	fscanf(file, "%d%d", &n, &m);
	memset(G, 0, sizeof(G));
	memset(vis, 0, sizeof(vis));
	int u, v;
	for(int i=0;i<m;i++)
	{
		fscanf(file, "%d%d", &u, &v);
		G[u][v] = G[v][u] = 1;  //����ͼ
	}
	euler(0);
	fclose(file);
	return 0;
}


