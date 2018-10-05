#include <stdio.h>
#include <string.h>
const int MAXN = 100;
int n, m, xs, ys, xt, yt; //n*m�ľ���(xs,ys)Ϊ���,(xt,yt)Ϊ�յ�

//����Ķ�ά����ֱ��ʾ���󣬽���Ƿ񱻷��ʹ�������㣬�Ӹ������չ���ķ����Լ��������ĳ���
int maze[MAXN][MAXN], vis[MAXN][MAXN], father[MAXN][MAXN], fa_dir[MAXN][MAXN], distance[MAXN][MAXN];

int dx[] = {-1,1,0,0}; //����������չʱ������x�ı仯ֵ
int dy[] = {0,0,-1,1}; //����������չʱ������y�ı仯ֵ
char dir[] = {'U','D','L','R'};

int queue[MAXN*MAXN];  //��ʾ����
//����㿪ʼ��չ
void bfs(int x, int y){
	// front��rear������չ�Ķ���,rear��������������ӽ��,front����ȡ���;
	//d��ʾ�������ҷ���;num��ʾ���ı��(ȡֵ��0��n*m)
	int front = 0, rear = 0, d, num; 
	num = x*m + y;
	vis[x][y] = 1;
	father[x][y] = num;
	distance[x][y] = 0;
	queue[rear++] = num; //�������ӵ�������
	while(front<rear)  //front == rearʱ����չ��ϣ�ѭ������
	{
		num = queue[front++]; //ȡ���
		x = num/m;
		y = num%m;
		//���������ĸ�������չ
		for(d = 0;d < 4; d++)
		{
			int nx = x+dx[d];
			int ny = y+dy[d];
			//���(nx,ny)���Ϸ�����û����չ�������ǿ�ͨ��
			if(nx>=0 && nx<n && ny>=0 && ny<n && maze[nx][ny] && !vis[nx][ny])
			{
				int v = nx*m + ny;
				queue[rear++] = v; //��������ӽ��
				vis[nx][ny] = 1;
				father[nx][ny] = num;
				fa_dir[nx][ny] = d;
				distance[nx][ny] = distance[x][y] + 1;
			}
		}
	}
}

//���յ㿪ʼ������·��,ʹ�õݹ�
void print_path(int x, int y)
{
	int fx = father[x][y]/m;
	int fy = father[x][y]%m;
	//û�ص����ʱ
	if(fx != x || fy != y)
	{
		print_path(fx,fy);
		putchar(dir[fa_dir[x][y]]);
	}
}

//���յ㿪ʼ������·��,ʹ��ѭ��
int path[MAXN*MAXN]; //��¼·��
void print_path2(int x, int y)
{
	int n = 0; 
	for(;;)
	{
		int fx = father[x][y]/m;
		int fy = father[x][y]%m;
		//�ص����ʱ
		if(fx == x && fy == y) break;
		path[n++] = fa_dir[x][y];
		x = fx;
		y = fy;
	}
	while(n--)
	{
		putchar(dir[path[n]]);
	}
}

int main()
{
	FILE * file;
	file = fopen("maze.in", "rb");
	fscanf(file,"%d%d%d%d%d%d", &n, &m, &xs, &ys, &xt, &yt);
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			fscanf(file, "%d", &maze[i][j]);
	bfs(xs,ys);
	print_path(xt,yt);
	printf("\n");
	print_path2(xt,yt);
	printf("\n");
	printf("%d\n",distance[xt][yt]);
	fclose(file);
	return 0;
}

