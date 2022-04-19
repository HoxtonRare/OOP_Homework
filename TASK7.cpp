#include <iostream>
#include <memory>
using namespace std;


class Date {
private:
	int m_day;
	int m_month;
	int m_year;
public:
	Date(int day, int month, int year) : m_day(day), m_month(month), m_year(year) {}

	void setDay(int day)
	{
		m_day = day;
	}
	int getDay() const
	{
		return m_day;
	}
	void setMonth(int month)
	{
		m_month = month;
	}
	int getMonth() const
	{
		return m_month;
	}
	void setYear(int year)
	{
		m_year = year;
	}
	int getYear() const
	{
		return m_year;
	}
};

ostream& operator << (ostream& os, const Date& date)
{
	os << date.getDay() << '/' << date.getMonth() << '/' << date.getYear() << endl;
	return os;
}

Date comp(Date& date1, Date& date2)
{
	if (date1.getYear() > date2.getYear())
	{
		return date1;
	}
	else if (date1.getMonth() > date2.getMonth())
	{
		return date1;
	}
	if (date1.getYear() == date2.getYear() && date1.getMonth() == date2.getMonth())
	{
		if (date1.getDay() > date2.getDay())
		{
			return date1;
		}
		else 
		{
			return date2;
		}
	}
	else
	{
		return date2;
	}
}

void mov(Date& date1, Date& date2)
{
	swap(date1, date2);
}

int main()
{
	setlocale(LC_ALL, "Rus");

	//Задание 1
	unique_ptr<Date> today(new Date(16, 4, 2022));
	unique_ptr<Date> date(new Date(30, 2, 1991));

	cout << "Day: " <<  today->getDay() << endl;
	cout << "Month: " << today->getMonth() << endl;
	cout << "Year: " << today->getYear() << endl;
	cout << *today << endl;
	date = move(today);
	cout << *date << endl;

	if (today)
	{
		cout << "Указатель today не является нулевым" << endl;
	}
	else
	{
		cout << "Указатель today является нулевым" << endl;
	}
	if (date)
	{
		cout << "Указатель date не является нулевым" << endl;
	}
	else
	{
		cout << "Указатель date является нулевым" << endl;
	}

	//Задание 2
	unique_ptr<Date> date1(new Date(23, 7, 2008));
	unique_ptr<Date> date2(new Date(12, 11, 2007));

	cout << comp(*date1, *date2) << endl;

	cout << "Даты до обмена: " << endl;
	cout << "Date1: " <<  *date1 << endl;
	cout << "Date2: " <<  *date2 << endl;
	mov(*date1, *date2);
	cout << "Даты после обмена: " << endl;
	cout << "Date1: " <<  *date1 << endl;
	cout << "Date2: " <<  *date2 << endl;

	return 0;
}