#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
class Book

{

private:

 char *name;                //����

 char *author;              //����

 int sale;                  //������

public:

 Book();                               //�޲ι��캯��

 Book(char *a, char *b, int c);         //�вι��캯��

 Book(const Book &book);   //�������캯��

 void print();                           //��ʾ����

 ~Book();                              //��������

};
Book::Book()
{
	name = new char[110];
	author = new char[110];
	strcpy(name,"No name");
	strcpy(author,"No author");
	sale = 0;
}
Book::Book(char *a, char *b, int c)
{
	name = new char[110];
	author = new char[110];
	strcpy(name,a);
	strcpy(author,b);
	sale = c;
}
Book::Book(const Book &book)
{
	name = new char[110];
	author = new char[110];
	strcpy(name,book.name);
	strcpy(author,book.author);
	sale = book.sale;
}
Book::~Book()
{
	delete []name;
	delete []author;
}
void Book::print()
{
	printf("Name: %s\tAuthor: %s\tSale: %d\n",name,author,sale);
}
int main()
{
	char s1[110];
	char s2[110];
	int s3;
	gets(s1);
	gets(s2);
	cin>>s3;
	if(strcmp(s1,"-1")==0&&strcmp(s2,"-1")==0&&s3==-1)
	{
		Book bk1;
		Book bk2(bk1);
		bk2.print();
	}
	else if(strcmp(s1,"0")==0&&strcmp(s2,"0")==0&&s3==0)
	{
		Book bk1;
		Book bk2(bk1);
		bk2.print();
	}
	else
	{
		Book bk2(s1,s2,s3);
		bk2.print();
	}
	
	return 0;
}
