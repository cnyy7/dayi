// {0~n-1}�������Ӽ���λ������
// Rujia Liu
#include<cstdio>
using namespace std;

void print_subset(int n, int* B, int cur) {
  if(cur == n) {
    for(int i = 0; i < cur; i++)
      if(B[i]) printf("%d ", i); // ��ӡ��ǰ����
    printf("\n");
    return;
  }
  B[cur] = 1; // ѡ��cur��Ԫ��
  print_subset(n, B, cur+1);
  B[cur] = 0; // ��ѡ��cur��Ԫ��
  print_subset(n, B, cur+1);
}

int B[10];
int main() {
  int n;
  scanf("%d", &n);
  print_subset(n, B, 0);
  return 0;
}
