#include<stdio.h>
#include<queue>
using namespace std;

queue<int> q;

int main()
{
	int n;
	scanf("%d", &n);
	
	for(int i=0;i<n;i++) q.push(i+1); //��ʼ������

	while(!q.empty())                 //�����зǿ�ʱ
	{
		printf("%d ", q.front());     //�������Ԫ��
		q.pop();                      //�Ƴ���һԪ��
		q.push(q.front());            //�Ѷ���Ԫ���Ƶ���β
		q.pop();                      //�Ƴ���һԪ��
	}
	printf("\n");
	return 0;
}