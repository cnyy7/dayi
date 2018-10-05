#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<string>
#include<queue>
#include<algorithm>
#include<map>
#include<iomanip>
#define INF 99999999
using namespace std;

typedef pair<int,int>mp;

struct cmp{
	bool operator()(mp a,mp b){//first��ʾλ��,second��ʾ����
		if(a.first == b.first)return a.second>b.second;//�����С��������
		return a.first>b.first;//λ�ô�С�������� 
	}
};

priority_queue<mp,vector<mp>,cmp>oq;

int main()
{										//���ȶ��в��븴�Ӷ�logN 
	int t,n,a,b;
	cin>>t;
	while(t--){
		cin>>n;
		while(!oq.empty())
			oq.pop();
		for(int i=0;i<n;++i){
			cin>>a>>b;
			oq.push(mp(a,b));
		}
		int num=1;
		mp next;
		while(!oq.empty())
		{
			next=oq.top();
			oq.pop();
			if(num&1)oq.push(mp(next.first+next.second,next.second));
			++num;
		}
		printf("%d\n",next.first);
	}
	return 0;
} 
