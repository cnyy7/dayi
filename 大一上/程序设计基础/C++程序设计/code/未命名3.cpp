#include<cstdio>
#include<iostream>
using namespace std;
class Time
{
	private:
		int hour;
		int min;
		int sec;
	public:
		Time(int hour,int min,int sec)
		{
			cout<<"Time"<<endl;
			this->hour=hour;
			this->min=min;
			this->sec=sec;
		}
		~Time()
		{
			cout<<"~"<<endl;
		}
		get_hour()
		{
			return hour;
		}
		get_min()
		{
			return min;
		}
		get_sec()
		{
			return sec;
		}
};
class Date
{
	private:
		int year;
		int mon;
		int day;
	public:
		Date(int year,int mon,int day)
		{
			cout<<"Date"<<endl;
			this->year=year;
			this->mon=mon;
			this->day=day;
		}
		int get_year()
		{
			return year;
		}
		get_mon()
		{
			return mon;
		}
		get_day()
		{
			return day;
		}
};
class schelude
{
	private:
		int no;
		Time time;
		Date date;
	public:
		schelude(int no,int hour,int min,int sec,int year,int mon,int day) : time(hour,min,sec) , date( year, mon, day)
		{
			cout<<"schelude"<<endl;
			this->no=no;
		}
	void show()
		{
			cout<<no<<endl;
			cout<<date.get_year()<<"��"<<date.get_mon()<<"��"<<date.get_day()<<"��"<<time.get_hour()<<"ʱ"<<time.get_min()<<"��"<<time.get_sec()<< "��"<<endl;
		}
	
};
int main()

{
	schelude T(1,7,17,53,2017,3,18);
	T.show();
	return 0;
	
}





















