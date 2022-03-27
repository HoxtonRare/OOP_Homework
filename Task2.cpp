#include <iostream>
#include <string>

using namespace std;

int numOfStudents = 0;

class Person {
protected:
	string m_name;
	int m_age;
	char m_sex;
	int m_weight;
public:
	Person(string name = "Ivan", int age = 0, char sex = 'M', int weight = 5) : m_name(name), m_age(age), m_sex(sex), m_weight(weight)
	{
		cout << "Person " << m_name << " was born" << endl;
	}
	~Person()
	{
		cout << "Person " << m_name << " died" << endl;
	}
	void changeName(string name)
	{
		m_name = name;
	}
	void changeAge(int age)
	{
		m_age = age;
	}
	void changeWeight(int weight)
	{
		m_weight = weight;
	}
};

class Student : public Person
{
protected:
	int m_yearOfStudy;
public:
	Student(string name = "Ivan", int age = 18, char sex = 'M', int weight = 55) : Person(name, age, sex, weight)
	{
		cout << "Student " << m_name << " started learning" << endl;
		numOfStudents++;
	}
	~Student()
	{
		cout << "Student " << m_name << " ending learning" << endl;
		numOfStudents--;
	}
	void changeYear(int year)
	{
		m_yearOfStudy = year;
	}
	void increase(int num)
	{
		m_yearOfStudy += num;
	}
	void printInfo()
	{
		cout << "INFO ABOUT STUDENT: " << endl;
		cout << m_name << endl << m_age << endl << m_sex << endl << m_weight << endl << endl;
	}
};

class Fruit {
protected:
	string m_name;
	string m_color;
public:
	Fruit(string name = "apple", string color = "Red") : m_name(name), m_color(color)
	{
	}
	string getName()
	{
		return m_name;
	}
	string getColor()
	{
		return m_color;
	}
};

class Apple : virtual public Fruit{
public:
	Apple(string color = "red", string name = "Apple") : Fruit(name, color)
	{
	}

};

class Banana : public Fruit {
public:
	Banana(string name = "Banana", string color = "yellow") : Fruit (name, color)
	{
	}

};

class GrannySmith : public Apple {
public:
	GrannySmith(string color = "green", string name = "Granny Smith apple") : Fruit (name, color)
	{
	}

};

int main()
{
	//Задание 1:
	setlocale(LC_ALL, "Rus");
	string name;
	int age;
	char sex;
	int weight;

	cout << "Введите имя: " << endl;
	getline(cin, name);
	cout << "Введите возраст: " << endl;
	cin >> age;
	cout << "Выберите пол(М/Ж): " << endl;
	cin >> sex;
	cout << "Введите вес: " << endl;
	cin >> weight;
	cout << endl;

	Student first(name, age, sex, weight);
	first.printInfo();
	Student second;
	second.printInfo();
	cout << "Количество студентов: " << numOfStudents << endl;
	cout << endl;

	//Задание 2:
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	
	cout << endl;

	return 0;
}

/*Думаю, что реализовать блэкджек можно в виде 3 базовых классов в виде игрока, хода игры и колоды. И производными классами в виде ранга карты от 2 до туза,
и производным классом противника.
Игроку прописать функции позволяющие взять карту, не брать карту, выводить сумму
В ход игры прописать конструктор преветствующий игрока  и перемешивающий карты, и функции раздачи карт, определение победителя
В колоду прописать количество карт, функцию удаления карт из колоды после раздачи
Противник будет наследовать класс игрока с добавлением функции рассчёта победного действия(брать, не брать карту)*/