#include <stdio.h>
#include <string.h>
const int MAXN = 50;

int matrix[MAXN][MAXN], visited[MAXN][MAXN];

void dfs(int row, int col)
{
	if(!matrix[row][col] || visited[row][col]) return;  //0��1�ڣ���Ԫ�񱻷��ʹ������ǰ�ɫ
	visited[row][col] = 1; //��Ƿ��ʹ�
	//�ݹ������Χ��8������
	dfs(row-1,col-1);
	dfs(row-1,col);
	dfs(row-1,col+1);
	dfs(row,col-1);
	dfs(row,col+1);
	dfs(row+1,col-1);
	dfs(row+1,col);
	dfs(row+1,col+1);
}

int main()
{
	int n;
	scanf("%d", &n);
	char s[MAXN];
	memset(matrix, 0 ,sizeof(matrix));  
	memset(visited, 0, sizeof(visited));
	for(int i=0;i<n;i++)
	{
		scanf("%s",s);
		for(int j=0;j<n;j++)
			matrix[i+1][j+1] = s[j] - '0'; //�ճ�һȦ�׸���
	}
	int count = 0;
	for(i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			if(matrix[i][j] && !visited[i][j])
			{
				count++;
				dfs(i,j);
			}
	printf("%d\n", count);
	return 0;
}