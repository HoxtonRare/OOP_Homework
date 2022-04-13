#include <iostream>
#include <vector>
#include <string>

using namespace std;

ostream& endll(ostream& a)
{
	a << "\n\n";
	return a;
}

void checkNumber()
{
	double num;
	cout << "Введите число: " << endl;
	while (!(cin >> num) || (cin.peek() != '\n'))
	{
		cin.clear();
		while (cin.get() != '\n');
		cout << "Некорректное число. Попробуйте ещё раз" << endll;
	}
}

class Card {
	friend ostream& cout(ostream& os, class Card);
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
	bool pos = false;
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
	bool getPos() const
	{
		return this->pos;
	}
	char getSuit() const
	{
		switch (this->cardSuit)
		{
		case Clubs:return static_cast<char>(5); break;
		case Diamonds:return static_cast<char>(4); break;
		case Hearts:return static_cast<char>(3); break;
		case Spades:return static_cast<char>(6); break;
		}
	}
	Card(value cValue, suit cSuit, bool ps) : cardValue(cValue), cardSuit(cSuit), pos(ps) {}
protected:
	suit cardSuit;
	value cardValue;
};

class Hand {
protected:
	vector<Card*>myCards;
public:
	void add(Card* card)
	{
		myCards.push_back(card);
	}
	void clear()
	{
		myCards.clear();
	}
	int getValue() const
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
	vector<Card*> GetCards() const
	{
		return myCards;
	}
};

class GenericPlayer : public Hand {
protected:
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
	string GetName() const
	{
		return name;
	}
};

class Player : public GenericPlayer {
public:
	Player(string pname) : GenericPlayer(pname) {}
	virtual bool IsHitting() const {
		char ans;
		cout << "Нужна ли ещё одна карта?(Y/N)" << endl;
		cin >> ans;
		while (ans != 'Y' || ans != 'N')
		{
			cout << "Некорректный ответ. Пожалуйста выберите (Y/N)" << endl;
		}
		if (ans == 'Y')
		{
			return true;
		}
		else if (ans == 'N')
		{
			return false;
		}
	}
	void Win() const
	{
		cout << "Игрок " << name << " выиграл!" << endl;
	}
	void Lose() const
	{
		cout << "Игрок " << name << " проиграл!" << endl;
	}
	void Push() const
	{
		cout << "Игрок " << name << " сыграл вничью" << endl;
	}
};

class House : public GenericPlayer {
public:
	House(string str) : GenericPlayer(str) {}
	virtual bool IsHitting() const
	{
		if (this->getValue() < 16)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void FlipFirstCard()
	{
		myCards[0]->Flip();
	}
};

ostream& operator << (ostream& os, const Card& card)
{
	if (card.getPos() == false)
	{
		return os << "XX";
	}
	else
	{
		switch (card.getValue())
		{
		case card.Ace: return os << 'A' << card.getSuit(); break;
		case card.Jack: return os << 'J' << card.getSuit(); break;
		case card.Queen: return os << 'Q' << card.getSuit(); break;
		case card.King: return os << 'K' << card.getSuit(); break;
		default: return os << card.getValue() << card.getSuit();
		}
	}
}

ostream& operator << (ostream& os, const GenericPlayer& gp)
{
	os << gp.GetName() << " : ";
	for (int i = 0; i < gp.GetCards().size(); i++)
	{
		os << gp.GetCards()[i];
	}
	os << " : " << gp.getValue();
	return os;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	checkNumber();
	return 0;
}