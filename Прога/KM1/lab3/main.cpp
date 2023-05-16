#include <iostream>
#include <sstream>
#include <stdio.h>
#include <string.h>

using namespace std;

typedef char *stadium;

const int sportssize = 5;
const string sportslist[sportssize] = {"Ski", "Skate", "Hockey", "Biatlon", "Bobsley"};

template <class T>
class set
{
	int size;
	T *ptr;

public:ptr
	set()
	{
		size = 0;
		ptr = nullptr;
	}

	~set() { delete[] ptr; }

	int getsize() { return size; }

	void resize(int newsize)
	{
		if (size == 0)
			ptr = new T[newsize];
		else if (newsize != 0)
		{
			T *temp = new T[newsize];
			memcpy(temp, ptr, newsize * sizeof(T));

			delete[] ptr;
			ptr = temp;
			temp = nullptr;
		}
		else
		{
			delete[] ptr;
			ptr = nullptr;
		}

		size = newsize;
	}

	void insert()
	{
		T x;

		cin >> x;

		bool flag = true;

		for (int i = 0; i < size; i++)
			if (ptr[i] == x)
				flag = false;

		if (flag)
		{
			resize(size + 1);
			ptr[size - 1] = x;
		}
	}

	void insert(T x)
	{
		bool flag = true;

		for (int i = 0; i < size; i++)
			if (ptr[i] == x)
				flag = false;

		if (flag)
		{
			resize(size + 1);
			ptr[size - 1] = x;
		}
	}

	void erase()
	{
		T x;

		cin >> x;

		int idx = -1;
		int i = 0;

		while (idx == -1 && i < size)
		{
			if (ptr[i] == x)
				idx = i;

			i++;
		}

		if (idx != -1)
		{
			for (i = idx; i < size - 1; i++)
				ptr[i] = ptr[i + 1];
			resize(size - 1);
		}
	}

	void erase(T x)
	{
		int idx = -1;
		int i = 0;

		while (idx == -1 && i < size)
		{
			if (ptr[i] == x)
				idx = i;

			i++;
		}

		if (idx != -1)
		{
			for (i = idx; i < size - 1; i++)
				ptr[i] = ptr[i + 1];
			resize(size - 1);
		}
	}

	bool in(T x)
	{
		for (int i = 0; i < size; i++)
			if (ptr[i] == x)
				return true;
		return false;
	}

	set<T> &operator+=(const set<T> &x)
	{
		for (int i = 0; i < x.size; i++)
			this->insert(x.ptr[i]);
		return *this;
	}

	set<T> &operator*=(const set<T> &x)
	{
		int flag = false;

		while (!flag && size > 0)
		{
			flag = true;

			int i = 0;
			while (flag && i < size)
			{
				if (!const_cast<set<T> &>(x).in(this->ptr[i]))
				{
					this->erase(this->ptr[i]);
					flag = false;
				}

				i++;
			}
		}

		return *this;
	}

	template <class T>
	friend istream &operator>>(istream &in, set<T> &s);

	template <class T>
	friend ostream &operator<<(ostream &out, set<T> const &s);
};

template <>
set<char *>::~set()
{
	for (int i = 0; i < size; i++)
		delete[] ptr[i];
	delete[] ptr;
}

template <>
void set<stadium>::resize(int newsize)
{
	if (size == 0)
		ptr = new char *[newsize];
	else if (newsize != 0)
	{
		char **temp = new char *[newsize];

		unsigned int memsize = 0;
		for (int i = 0; i < newsize; i++)
			memsize += sizeof(ptr[i]);
		memcpy(temp, ptr, memsize);

		delete[] ptr;
		ptr = temp;
		temp = nullptr;
	}
	else
	{
		delete[] ptr;
		ptr = nullptr;
	}

	size = newsize;
}

template <>
void set<stadium>::insert(stadium str)
{
	bool flag = true;

	for (int i = 0; i < size; i++)
		if (strcmp(ptr[i], str) == 0)
			flag = false;

	if (flag)
	{
		resize(size + 1);
		ptr[size - 1] = new char[sizeof(str)];
		strcpy(ptr[size - 1], sizeof(str));
	}
}

template <>
void set<stadium>::erase(char *str)
{
	int idx = -1;
	int i = 0;

	while (idx == -1 && i < size)
	{
		if (strcmp(ptr[i], str) == 0)
			idx = i;

		i++;
	}

	if (idx != -1)
	{
		for (i = idx; i < size - 1; i++)
		{
			delete[] ptr[i];
			ptr[i] = new char[sizeof(ptr[i + 1])];
			strcpy(ptr[i], sizeof(ptr[i + 1]));
		}
		delete[] ptr[size - 1];
		resize(size - 1);
	}
}

template <class T>
istream &operator>>(istream &in, set<T> &s)
{
	s.insert();
	return in;
}

template <>
istream &operator>>(istream &in, set<stadium> &s)
{
	string str;
	string sport;

	getline(in, str);

	istringstream iss(str);

	while (iss >> sport)
	{
		bool flag = false;
		int i = 0;

		while (!flag && i < sportssize)
		{
			if (strcmp(sport.c_str(), sportslist[i].c_str()) == 0)
			{
				s.insert((char *)sport.c_str());
				flag = true;
			}

			i++;
		}
	}

	return in;
}

template <class T>
ostream &operator<<(ostream &out, set<T> const &s)
{
	out << "{ ";

	if (size == 0)
		out << "Empty";
	else
		for (int i = 0; i < s.size; i++)
		{
			out << s.ptr[i];
			if (i < s.size - 1)
				out << ", ";
		}
	out << " }";

	return out;
}

void task(set<stadium> *s, int size)
{
	set<stadium> a;
	set<stadium> b;

	for (int i = 0; i < size; i++)
		a += s[i];

	for (int i = 0; i < sportssize; i++)
		b.insert((char *)sportslist[i].c_str());

	for (int i = 0; i < size; i++)
		b *= s[i];

	cout << endl;
	cout << "Виды спорта, секции по которым имеются хотя бы на одном стадионе: " << a << endl;
	cout << "Виды спорта, секции по которым имеются на всех стадионах: " << b;
}

int main(void)
{

	int size;
	set<stadium> *s;

	cout << "Введите количество стадионов: ";
	cin >> size;
	cin.ignore();

	s = new set<stadium>[size];

	cout << "Введите список секций для каждого стадиона:" << endl;
	for (int i = 0; i < size; i++)
		cin >> s[i];

	cout << endl
		 << "Список стадионов:" << endl;
	for (int i = 0; i < size; i++)
		cout << s[i] << endl;

	task(s, size);

	delete[] s;

	return 0;
}