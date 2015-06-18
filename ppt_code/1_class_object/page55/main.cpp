/********************************************************************
  > File Name: main.cpp
  > Author: he_CentOS
  > Mail:1778195296@qq.com 
  > Created Time: 2015年03月13日 星期五 11时56分13秒
 *******************************************************************/
#if 0
定义一个满足如下要求的Date类
a)用下面的格式输出日期 
  年.月.日 (2010.1.31)
b)可以运行在日期上加一天操作
c)设置日期操作
d) 年,月,日可以各用一个整数表示
#endif

#include<iostream>
#include<iomanip>
using namespace std;
#define ISLEAPYEAR(year) (year % 400 ==0 || year % 4 == 0 && year % 100 != 0)

class date
{
	private:
		int iyear;
		int imonth;
		int iday;

	public:
		date(int year = 1970, int month = 1, int day = 1)
		{
			iyear = year;
			imonth = month;
			iday = day;
		}

		//左++
		date& operator++()
		{
			add_one_day(*this);
			return (*this);
		}
		//右++
		date& operator++(int)
		{
			date* olddate = new date(iyear, imonth, iday);
			++(*this);
			return (*olddate);
		}

		date& add_one_day(date& da);

		void print() const
		{
			cout << iyear << '.' << setfill('0') << setw(2) << imonth  << '.' << setw(2) << iday << endl;
		}
};

date& date::add_one_day(date& da)
{//计算指定日期在1天数后的日期
	int year = da.iyear;
	int month = da.imonth;
	int day = da.iday;
	switch(month)
	{
		case 1:  
		case 3:  
		case 5: 
		case 7: 
		case 8: 
		case 10: 
		case 12: 
			year = year + (month + (day + 1) / 32) / 13 ; 

			month = (month + (day + 1) / 32 ) % 13 +  (month + (day + 1) / 32) / 13;

			day  = (day + 1) %32 + (day + 1) / 32  ; 
			break ;
		case 4:  
		case 6:  
		case 9: 
		case 11: 
			month = month + (day + 1) / 31 ;

			day  = (day + 1) %31 + (day + 1) / 31  ; 
			break ;

		case 2:
			if(ISLEAPYEAR(year))
			{
				month = month + (day + 1) / 30 ; 
				day = (day + 1)%30 + (day + 1) / 30 ;
			}else 
			{
				month = month + (day + 1) / 29 ; 
				day = (day + 1)%29 + (day + 1) / 29 ;
			}
			break ;
	}
	da.iyear = year;
	da.imonth = month;
	da.iday = day;

	return da ;
}

int main(void)
{
	date dt1;
	dt1.print();

	date dt2(1010,12,31);
	dt2.print();
	((++dt2)++).print();
	dt2.print();

	return 0;
}
