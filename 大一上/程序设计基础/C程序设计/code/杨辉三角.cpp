#include <stdio.h>

/*int c(int x,int y)        //����������εĵ�x�е�y�е�ֵ
 {
  int z;
  if((y==1)||(y==x+1))    //��Ϊx�еĵ�1���x+1�У������1
  return (1);
  else 
  	z=c(x-1,y-1)+c(x-1,y);//������ֵΪǰһ���е�y-1�����y��ֵ֮��
  return (z);
 }

int main()
{
 	int i,j,n=100;
	printf("N=");
	while(n>12)
	scanf("%d",&n);    //����������ȷ��ֵ�Ա�֤��Ļ��ʾ��ͼ����ȷ
	for(i=0;i<=n;i++)    //�������N��
	{
   		for(j=0;j<12-i;j++)    //���������i��ǰ��Ŀո�
		   	printf(" ");
		for(j=1;j<i+2;j++)    //�����i�еĵ�j��ֵ
			printf("%6d",c(i,j));
		  printf("\n");
	}
}*/

int main() 
{ 
     int i,j,x,y,n=0,a[20]={0,1}; 
     while(n<1 || n>19) 
     { 
       scanf("%d",&n); 
     } 
     for(i=1;i<=n;i++) 
    { 
       x=0; 
       for(j=1;j<=i;j++) 
       { 
         y=a[j]; 
         a[j]=x+y; 
         x=y; 
         printf("%5d",a[j]); 
       } 
       printf("\n"); 
    } 
}
