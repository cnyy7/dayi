/*龟兔赛跑预测
发布时间: 2017年1月15日 01:17   时间限制: 1000ms   内存限制: 512M

描述
       话说这个世界上有各种各样的兔子和乌龟，但是 研究发现，所有的兔子和乌龟都有一个共同的特点——喜欢赛跑。于是世界上各个角落都不断在发生着乌龟和兔子的比赛，小华对此很感兴趣，于是决定研究不同兔 子和乌龟的赛跑。他发现，兔子虽然跑比乌龟快，但它们有众所周知的毛病——骄傲且懒惰，于是在与乌龟的比赛中，一旦任一秒结束后兔子发现自己领先t米或以 上，它们就会停下来休息s秒。对于不同的兔子，t，s 的数值是不同的，但是所有的乌龟却是一致——它们不到终点决不停止。

　　然而有些比赛相当漫长，全程观看会耗费大量时间，而小华发现只要在每场比赛开始后记录下兔子和乌龟的数据——兔子的速度 v1（表示每秒兔子能跑 v1 米），乌龟的速度 v2，以及兔子对应的 t，s 值，以及赛道的长度 l——就能预测出比赛的结果。但是小华很懒，不想通过手工计算推测出比赛的结果，于是他找 到了你——清华大学计算机系的高才生——请求帮助，请你写一个程序，对于输入的一场比赛的数据 v1，v2，t，s，l，预测该场比赛的结果。

输入
输入只有一行，包含用空格隔开的五个正整数v1，v2，t，s，l，其中(v1,v2<=100;t<=300;s<=10;l<=10000且为v1,v2的公倍数)

输出
输出包含两行，第一行输出比赛结果——一个大写字母“T”或“R”或“D”，分别表示乌龟获胜，兔子获胜，或者两者同时到达终点。?　　第二行输出一个正整数，表示获胜者（或者双方同时）到达终点所耗费的时间（秒数）。

样例输入1 复制
10 5 5 2 20
样例输出1
D
4
样例输入2 复制
10 5 5 1 20
样例输出2
R
3
样例输入3 复制
10 5 5 3 20
样例输出3
T
4
提示
None

标签
蓝桥杯

来源
Ivan
*/
#include<stdio.h>
int main()
{
	int v1,v2,t,s,l,s1=0,s2=0,T=0;
	scanf("%d%d%d%d%d",&v1,&v2,&t,&s,&l);
	while(s1<=l&&s2<=l)
	{
		s1+=v1;
		s2+=v2;
		T++;
		if(s1==l||s2==l)
			break;
		if(s1-s2>=t)
			s1-=v1*s;
	}
	if(s1>s2)
		printf("R\n");
	else if(s2>s1)
		printf("T\n");
	else if(s1==s2)
		printf("D\n");
	printf("%d\n",T);
	return 0;
}
