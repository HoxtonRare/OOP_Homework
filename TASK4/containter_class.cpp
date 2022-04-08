#include <iostream>
#include <algorithm>
#include <cassert> 

class ArrayInt
{
private:
	int m_length;
	int* m_data;

public:
	ArrayInt() : m_length(0), m_data(nullptr) { }

	ArrayInt(int length) :
		m_length(length)
	{
		assert(length >= 0);

		if (length > 0) {
			m_data = new int[length];
		}
		else {
			m_data = nullptr;
		}
	}

	~ArrayInt()
	{
		delete[] m_data;
	}

	void erase()
	{
		delete[] m_data;

		m_data = nullptr;
		m_length = 0;
	}

	int getLength() { return m_length; }

	int& operator[](int index)
	{
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	void resize(int newLength)
	{
		if (newLength == m_length) {
			return;
		}

		if (newLength <= 0) {
			erase();
			return;
		}

		int *data = new int[newLength];

		if (m_length > 0) {
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;

			for (int index = 0; index < elementsToCopy; ++index) {
				data[index] = m_data[index];
			}
		}

		delete[] m_data;

		m_data = data;
		m_length = newLength;
	}

	void insertBefore(int value, int index)
	{
		assert(index >= 0 && index <= m_length);

		int* data = new int[m_length + 1];

		for (int before = 0; before < index; ++before) {
			data[before] = m_data[before];
		}

		data[index] = value;

		for (int after = index; after < m_length; ++after) {
			data[after + 1] = m_data[after];
		}

		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void push_back(int value) { insertBefore(value, m_length); }

	int pop_back()
	{
		assert(m_length > 0);
		return m_data[--m_length];
	}

	int pop_front()
	{
		assert(m_length > 0);
		int value = m_data[0];

		for (int index = 0; index < (m_length - 1); ++index)
		{
			m_data[index] = m_data[index + 1];
		}
		--m_length;
		return value;
	}

	void printArr() const
	{
		if (m_length <= 0)
		{
			std::cout << "Массив пуст" << std::endl;
		}

		for (int index = 0; index < m_length; ++index)
		{
			std::cout << m_data[index] << " ";
		}
		std::cout << std::endl;
	}

	void sortArr()
	{
		std::sort(m_data, (m_data + m_length));
	}
};

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "Rus")
	ArrayInt arrayInt;
	arrayInt.push_back(100);
	arrayInt.push_back(1);
	arrayInt.push_back(0);
	arrayInt.push_back(10);
	arrayInt.pop_back();
	arrayInt.pop_front();
	arrayInt.sortArr();
	arrayInt.printArr();
	return 0;
}
