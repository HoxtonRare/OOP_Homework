#include <iostream>
#include <string>
using namespace std;

class Figure {
protected:
	int m_side1;
	int m_side2;
	Figure(int side1 = 1, int side2 = 1) : m_side1(side1), m_side2(side2)
	{
		cout << "Figure was created" << endl;
	};
public:
	virtual void area() = 0;
};

class Parallelogram : public Figure {
public:
	Parallelogram(int side = 2, int height = 1) : Figure(side, height)
	{
		cout << "Parallelogram was created" << endl;
	}
	void area()
	{
		int s;
		s = m_side1 * m_side2;
		cout << "Площадь параллелограмма = " << s << endl << endl;
	}
};

class Circle : public Figure {
public:
	Circle(double p = 3.14, int r = 2) : Figure(p, r)
	{
		cout << "Circle was created" << endl;
	}
	void area()
	{
		double s;
		s = 3.14 * pow(m_side2, 2);
		cout << "Площадь круга = " << s << endl << endl;
	}
};

class Rectangle : public Parallelogram {
public:
	Rectangle(int length = 2, int width = 1) : Parallelogram (length, width)
	{
		cout << "Rectangle was created" << endl;
	}
	void area()
	{
		int s;
		s = m_side1 * m_side2;
		cout << "Площадь прямоугольника = " << s << endl << endl;
	}
};

class Square : public Parallelogram {
public:
	Square(int side = 2) : Parallelogram (side)
	{
		cout << "Square was created" << endl;
	}
	void area()
	{
		int s;
		s = pow(m_side1, 2);
		cout << "Площадь квадрата = " << s << endl << endl;
	}
};

class Rhombus : public Parallelogram {
public:
	Rhombus(int side = 1, int height = 2) : Parallelogram (side, height)
	{
		cout << "Rhombus was created" << endl;
	}
	void area()
	{
		int s;
		s = m_side1 * m_side2;
		cout << "Площадь ромба = " << s << endl << endl;
	}
};

class Car {
protected:
	string Company;
	string model;
public:
	Car()
	{
		cout << "Car was created" << endl;
	}
};

class PassengerCar : virtual public Car {
public:
	PassengerCar()
	{
		cout << "PassengerCar was created" << endl;
	}
};

class Bus : virtual public Car {
public:
	Bus()
	{
		cout << "Bus was created" << endl;
	}
};

class Minivan : public Bus, PassengerCar
{
public:
	Minivan()
	{
		cout << "Minivan was created" << endl;
	}
};

class Fraction {
public:
	int m_numerator;
	int m_denominator;
	Fraction(int num, int den) : m_numerator(num), m_denominator(den)
	{}
	void printFr()
	{
		cout << m_numerator << '/' << m_denominator << endl;
	}
};

Fraction operator + (Fraction f1, Fraction f2)
{
	return Fraction(f1.m_numerator * f2.m_denominator + f1.m_denominator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}
Fraction operator * (Fraction f1, Fraction f2)
{
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}
Fraction operator / (Fraction f1, Fraction f2)
{
	swap(f2.m_denominator, f2.m_numerator);
	return Fraction(f1.m_numerator * f2.m_numerator, f1.m_denominator * f2.m_denominator);
}
Fraction operator - (Fraction f1)
{
	return Fraction(f1.m_numerator = -f1.m_numerator, f1.m_denominator = -f1.m_denominator);
}
bool operator == (Fraction f1, Fraction f2)
{
	if (f1.m_numerator == f2.m_numerator && f1.m_denominator == f2.m_denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator != (Fraction f1, Fraction f2)
{
	if (f1.m_numerator != f2.m_numerator && f1.m_denominator != f2.m_denominator)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator > (Fraction f1, Fraction f2)
{
	int a, b;
	a = f1.m_numerator / f1.m_denominator;
	b = f2.m_numerator / f2.m_denominator;
	if (a > b)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator < (Fraction f1, Fraction f2)
{
	if (f1 > f2)
	{
		return false;
	}
	else
	{
		return true;
	}
}
bool operator >= (Fraction f1, Fraction f2)
{
	if (f1 > f2)
	{
		return true;
	}
	else if (f1 == f2)
	{
		return true;
	}
	else
	{
		return false;
	}
}
bool operator <= (Fraction f1, Fraction f2)
{
	if (f1 < f2)
	{
		return true;
	}
	else if (f1 == f2)
	{
		return true;
	}
	else
	{
		return false;
	}
}

class Card {
protected:
	int m_rank = 6;
	enum suit {
		Hearts,
		Spades,
		Diamonds,
		Clubs
	};
	enum value {
		Ace = 1,
		Two = 2,
		Three = 3,
		Four = 4,
		Five = 5,
		Six = 6,
		Seven = 7,
		Eight = 8,
		Nine = 9,
		Ten = 10,
		Jack = 10,
		Queen = 10,
		King = 10
	};
	bool pos = false;
	value cardValue;
public:
	void Flip()
	{
		if (pos == true)
		{
			pos = false;
		}
		else
		{
			pos = true;
		}
	}
	int GetValue() const
	{
		return cardValue;
	}
};


int main()
{
	//Задание 1
	setlocale(LC_ALL, "Rus");
	int side1;
	int side2;
	cout << "Введите размер стороны: " << endl;
	cin >> side1;
	cout << "Введите высоту: " << endl;
	cin >> side2;
	Parallelogram par(side1, side2);
	par.area();
	
	cout << "Введите радиус круга: " << endl;
	cin >> side2;
	Circle circ(3.14, side2);
	circ.area();

	cout << "Введите длину: " << endl;
	cin >> side1;
	cout << "Введите ширину" << endl;
	cin >> side2;
	Rectangle rec(side1, side2);
	rec.area();

	cout << "Введите размер стороны квадрата: " << endl;
	cin >> side1;
	Square square(side1);
	square.area();

	cout << "Введите размер стороны: " << endl;
	cin >> side1;
	cout << "Введите высоту: " << endl;
	cin >> side2;
	Rhombus rhombus(side1, side2);
	rhombus.area();

	//Задание 2
	Car car;
	PassengerCar passCar;
	Bus bus;
	Minivan mini;

	//Задание 3
	Fraction fr(3, 7);
	Fraction fr2(4, 2);

	Fraction fr3 = fr + fr2;
	fr3.printFr();
	Fraction fr4 = -fr;
	fr4.printFr();
	Fraction fr5 = fr * fr2;
	fr5.printFr();
	Fraction fr6 = fr / fr2;
	fr6.printFr();

	cout << (fr == fr2) << endl;
	cout << (fr != fr2) << endl;
	cout << (fr > fr2) << endl;
	cout << (fr < fr2) << endl;
	cout << (fr >= fr2) << endl;
	cout << (fr <= fr2) << endl;
	return 0;
}
