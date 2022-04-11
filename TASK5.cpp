#include <iostream>
#include <string>
#include <vector>

using namespace std;

template <class T>
class Pair1 {
private:
	T m1;
	T m2;
public:
	Pair1(T n1, T n2) : m1(n1), m2(n2) {};

	T first() const
	{
		return m1;
	}
	T second() const
	{
		return m2;
	}
};

template <class Type, class Type2>
class Pair {
private:
	Type m1;
	Type2 m2;
public:
	Pair(Type n1, Type2 n2) : m1(n1), m2(n2) {}
	Type first() const
	{
		return m1;
	}
	Type2 second() const
	{
		return m2;
	}
};

template <class T>
class StringValuePair : public Pair < string, T> {
public:
	StringValuePair(string n1, T n2) : Pair<string, T>(n1, n2) {}
};

class Card {
public:
	enum suit {
		Hearts,
		Spades,
		Diamonds,
		Clubs
	};
	enum value {
		Ace,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King
	};
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
	int getValue() const
	{
		return this->cardValue;
	}
protected:
	int m_rank = 6;
	suit cardSuit;
	value cardValue;
	bool pos = false;
};

class Hand {
private:
	vector<Card*>myCards;
public:
	void add(Card*)
	{
		myCards.push_back(new Card);
	}
	void clear()
	{
		myCards.clear();
	}
	int getValue()
	{
		int value = 0;
		bool ace = false;
		for (int i = 0; i < myCards.size(); i++)
		{
			if (myCards[i]->getValue() == Card::Ace)
			{
				ace = true;
			}

			else if (myCards[i]->getValue() == Card::Jack || myCards[i]->getValue() == Card::Queen || myCards[i]->getValue() == Card::King)
			{
				value += 10;
			}

			else
			{
				value += myCards[i]->getValue();
			}
		}
		if (ace && value <= 11)
		{
			value += 10;
		}
		return value;
	}
};

class GenericPlayer : public Hand {
private:
	string name;
public:
	GenericPlayer(string pName) : name(pName) {}
	virtual bool IsHitting() const = 0;
	bool isBoosted()
	{
		if (this->getValue() > 21)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void Bust()
	{
		cout << "У игрока " << name << " перебор" << endl;
	}
};

int main()
{
	//Задание 1
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';
	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';
	cout << endl;

	//Задание 2
	Pair<int, double> p3(6, 7.8);
	cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';
	const Pair<double, int> p4(3.4, 5);
	cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';
	cout << endl;

	//Задание 3
	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
	return 0;
}

