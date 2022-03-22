#include <iostream>
#include <cstdint>

using namespace std;

class Power
{
	int m_first = 2;
	int m_second = 2;
public:
	void set(int first, int second)
	{
		m_first = first;
		m_second = second;
	}
	void calculate()
	{
		int res = pow(m_first, m_second);
		cout << m_first << " в степени " << m_second << " = " << res << endl;
	}
};

class RGBA 
{
	uint8_t m_red = 0, m_green = 0, m_blue = 0, m_alpha = 255;
public:
	RGBA(int first, int sec, int third, int fourth) : m_red(first), m_green(sec), m_blue(third), m_alpha(fourth)
	{

	}
	void def()
	{
		m_red = 0;
		m_blue = 0;
		m_green = 0;
		m_alpha = 255;
	}
	void print()
	{
		cout << "m_red = " << m_red << endl;
		cout << "m_green = " << m_green << endl;
		cout << "m_blue = " << m_blue << endl;
		cout << "m_alpha = " << m_alpha << endl;
	}
};

class Stack
{
	int m_arr[10];
	int m_size = 0;
public:
	bool push(int num)
	{
		if (m_size <= 9)
		{
			m_arr[m_size] = num;
			++m_size;
			return true;
		}
		else
		{
			cout << "Стэк переполнен" << endl;
			return false;
		}
	}
	void reset()
	{
		for (int i = 0; i < m_size; i++)
		{
			m_arr[i] = 0;
		}
		m_size = 0;
	}
	void pop()
	{
		if (m_size < 0)
		{
			cout << "Стэк пуст" << endl;
		}
		else
		{
			m_arr[m_size] = 0;
			m_size--;
		}
	}
	void print()
	{
		cout << "( ";
		for (int i = 0; i < m_size; i++)
		{
			cout << m_arr[i] << " ";
		}
		cout << ')' << endl;
	}
};

int main()
{
	setlocale(LC_ALL, "Rus");
	//Задание 1
	cout << "ЗАДАНИЕ 1: \n\n";
	Power num;
	num.calculate();
	cout << endl;
	int firstNum;
	int secNum;
	cout << "Введите первое число: " << endl;
	cin >> firstNum;
	cout << "Введите второе число: " << endl;
	cin >> secNum;
	num.set(firstNum, secNum);
	num.calculate();

	//Задание 2
	cout << "\nЗАДАНИЕ 2: \n\n";
	int red;
	int green;
	int blue;
	int alpha;
	cout << "Введите значение RED: " << endl;
	cin >> red;
	cout << "Введите значение GREEN: " << endl;
	cin >> green;
	cout << "Введите значение BLUE: " << endl;
	cin >> blue;
	cout << "Введите значение ALPHA: " << endl;
	cin >> alpha;
	RGBA rgba(red, green, blue, alpha);
	rgba.print();


	//Задание 3
	cout << "\nЗАДАНИЕ 3: \n\n";
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
	return 0;
}