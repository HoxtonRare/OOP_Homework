#include <iostream>
#include <vector>
#include <string>
using namespace std;

template <typename T>
T div(T a, T b)
{
	a = static_cast<double>(a);
	if (!b)
	{
		throw "DivisionByZero";
	}
	return (a / b);
}


class Ex
{
private:
	double x;
public:
	Ex(double x) : x(x)
	{}
	double get()
	{
		return x;
	}
};

class Bar
{
private:
	double y;
public:
	Bar() : y(0)
	{}
	~Bar()
	{}
	void set(double a)
	{
		if (y + a > 100)
		{
			Ex ex(a*y);
			throw  ex;
		}
		else
		{
			y = a;
		}
	}
};

class IllegalCommand
{
private:
	int x, y, m;
public:
	IllegalCommand(int x, int y, int m) : x(x), y(y), m(m)
	{}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getM()
	{
		return m;
	}
};

class OffTheField
{
private:
	int x, y, m;
public:
	OffTheField(int x, int y, int m) : x(x), y(y), m(m)
	{}
	int getX()
	{
		return x;
	}
	int getY()
	{
		return y;
	}
	int getM()
	{
		return m;
	}
};

class Robot
{
private:
	int x, y;
public:
	Robot() : x(0), y(0)
	{}
	void move(int& m)
	{
		if (m < 1 || m > 4)
		{
			IllegalCommand ic(x, y, m);
			throw ic;
		}
		switch (m)
		{
		case 1:
			--x;
			if (x < 0)
			{
				++x;
				OffTheField otf(x, y, m);
				throw otf;
			}
			break;
		case 2:
			++y;
			if (y > 9)
			{
				--y;
				OffTheField otf(x, y, m);
				throw otf;
			}
			break;
		case 3:
			++x;
			if (x > 9)
			{
				--x;
				OffTheField otf(x, y, m);
				throw otf;
			}
			break;
		case 4:
			--y;
			if (y < 0)
			{
				++x;
				OffTheField otf(x, y, m);
				throw otf;
			}
			break;
		}
	}
	void getPosition()
	{
		cout << "Позиция робота: " << x << ',' << y << ')' << endl;
	}
};


int main()
{
	setlocale(LC_ALL, "Rus");
	//Задание 1
	int num1, num2;
	cout << "Введите первое число: " << endl;
	cin >> num1;
	cout << "Введите второе число: " << endl;
	cin >> num2;

	//Задание 2

	try
	{
		double c = div<double>(num1, num2);
		cout << "Результат деления: " << c << endl;
	}
	catch (const char* exeption)
	{
		cerr << "Ошибка " << exeption << endl;
	}

	Bar bar;
	double num = 0;

	while (num >= 0)
	{
		cout << "Введите число: ";
		cin >> num;
		try
		{
			bar.set(num);
		}
		catch (Ex& ex)
		{
			cerr << "Ошибка " << ex.get() << endl;
			break;
		}
	}

	//Задание 3

	Robot bot;

	cout << "Введите направление(1 - влево | 2 - вверх | 3 - вправо | 4 - вниз | Q - выйти): ";
	string str = "0";
	int direction;
	cin >> str;

	while (str != "Q")
	{

		direction = std::atoi(str.c_str());
		try
		{
			bot.move(direction);
		}
		catch (OffTheField& otf)
		{
			std::cerr << "Ошибка. Выход на поле. Координаты: (" << otf.getX() << ',' << otf.getY() << "), направление (" << otf.getM() << ')' << std::endl;
		}
		catch (IllegalCommand& ic)
		{
			std::cerr << "Ошибка. Некорректная команда: (" << ic.getX() << ',' << ic.getY() << "), направление (" << ic.getM() << ')' << std::endl;
		}

		std::cout << "Введите направление(1 - влево | 2 - вверх | 3 - вправо | 4 - вниз | Q - выйти): ";
		std::cin >> str;
	}
	return 0;
}
