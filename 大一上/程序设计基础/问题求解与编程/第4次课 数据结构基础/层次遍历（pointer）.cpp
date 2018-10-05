#include<stdio.h>
#include<stdlib.h>
#include<string.h>

const int MAXN = 256;

typedef struct TNode{
	int value;       
	int have_value;  //�Ƿ񱻸�ֵ��
	struct TNode * left, * right;

} Node;

Node * root;

Node * newnode()
{
	Node * node = (Node *)malloc(sizeof(Node));
	if(node != NULL)
	{
		node->have_value = 0;  //��ʾû�б���ֵ��
		node->left = node->right = NULL;
	}
	return node;
}

int failed;

void addnode(int v, char * s)
{
	int n = strlen(s);
	Node * node = root;   //�Ӹ��ڵ㿪ʼ������
	for(int i=0;i<n-1;i++)
	{
		if(s[i]=='L')
		{
			if(node->left==NULL) node->left = newnode(); //�ڵ㲻���ڣ������½ڵ�
			node = node->left;
		}
		if(s[i]=='R')
		{
			if(node->right==NULL) node->right = newnode();
			node = node->right;
		}
	}
	if(node->have_value) failed = 1; //�Ѿ���ֵ����������������
	node->value = v;
	node->have_value = 1;
}

void remove_tree(Node * node)
{
	if(node==NULL) return;
	remove_tree(node->left);
	remove_tree(node->right);
	free(node);
}

char s[MAXN+10];
int read_input()
{
	failed = 0;
	remove_tree(root);
	root = newnode();   //�������ڵ�
	while(1)
	{
		if(scanf("%s",s)!=1) return 0;  //�����������
		if(!strcmp(s,"()")) break;    //����()���˳�ѭ��
		int v;
		sscanf(&s[1],"%d",&v);       //����ڵ�ֵ
		addnode(v,strchr(s,',')+1);   //��ӽڵ�
	}
	return 1;
}

int n = 0, ans[MAXN];    //�ڵ��������������
int bfs() // ��ʼʱһ�����ڵ㣬ÿȡһ���ڵ㣬�������Ҷ��ӷ������
{
	int front = 0, rear = 1;
	Node * tree[MAXN];   //����
	tree[0] = root;
	while(front<rear)
	{
		Node * node = tree[front++];
		if(!node->have_value)  return 0; //�нڵ�û����ֵ��������������
		ans[n++] = node->value;
		if(node->left != NULL) tree[rear++] = node->left;
		if(node->right != NULL) tree[rear++] = node->right;
	}
	return 1;
}

int main()
{
	while(read_input())
	{
		if(!bfs()) failed = 1;
		if(failed) printf("-1\n");
		else
		{
			for(int i=0; i<n; i++)
				printf("%d ", ans[i]);
			printf("\n");
		}
	}
	return 0;
}