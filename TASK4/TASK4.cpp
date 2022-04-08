#include <iostream>
#include <vector>
using namespace std;

void checkVec(vector<int> v)
{
	int num = 1; 
	int vecSize = v.size() - 1;
		for (int i = 0; i < vecSize; i++)
		{
			for (int j = 0; j < vecSize; j++)
			{
				if (v[j] > v[j + 1])
				{
					swap(v[j], v[j + 1]);
				}
			}
		}
		for (int i = 0; i < vecSize; i++)
		{
			if (v[i] != v[i + 1])
			{
				num++;
			}
		}
	cout << "В векторе " << num << " разных чисел" << endl;
}

class Card {
public:
	enum suit {
		Hearts,
		Spades,
		Diamonds,
		Clubs
	};
	enum value {
		Ace = 1,
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


int main()
{
	setlocale(LC_ALL, "Rus");
	vector<int> v1;
	v1.push_back(5);
	v1.push_back(10);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(6);
	checkVec(v1);
	return 0;
}


