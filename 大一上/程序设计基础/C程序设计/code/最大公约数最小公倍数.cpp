#include<stdio.h>
int main()
{
	int a,b,i,j;
	printf("Please input two numbers:");
	scanf("%d%d",&a,&b);
	i=a*b;
	if(a<b)
	{
		j=a;
		a=b;
		b=j;
	}
	while(b!=0)
	{
		j=a%b;
		a=b;
		b=j;	
	}
	printf("���Լ���ǣ�%d\n��С�������ǣ�%d\n",a,i/a);
	return 0;
}
