#include<stdio.h>
int main()
{
	double a,b,c;
	printf("��������������") ;
	scanf("%lf%lf%lf",&a,&b,&c); 
	if(a<=0||b<=0||c<=0)
		printf("�����εı߳��������0\n"); 
	else 
		if((a==b&&a+b>c)||(a==c&&a+c>b)||(b==c&&b+c>a))
			printf("�ǵ���������\n");
		else
			printf("���ǵ���������\n");
	return 0;
}
