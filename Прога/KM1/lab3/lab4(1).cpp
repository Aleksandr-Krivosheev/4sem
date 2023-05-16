#include <iostream>
#include <string>


using namespace std;

                    /* структура бЛЮдаоаоаоао*/
struct dish
{
	string name;
	int cost;

public:
	dish() {
		name = '-';
		cost = 0;
	}
	int operator== (const dish& elem2) {
		return (cost == elem2.cost && name == elem2.name);
	};
	friend istream& operator>> (istream& in, const dish& elem);
	friend ostream& operator<< (ostream& out, const dish& elem);
	dish& operator= (const dish& elem) {
		name = elem.name;
		cost = elem.cost;
		return *this;
	};
	dish(const dish& elem) {
		name = elem.name;
		cost = elem.cost;
	};
};





istream& operator>> (istream& in, dish& elem) {
	in >> elem.name >> elem.cost;
	return in;
}

ostream& operator<< (ostream& out, const dish& elem) {
	out << "Блюдо: " << elem.name << endl << "Цена: " << elem.cost << " руб." << endl;
	return out;
}


 class set {
private:
	int size;
	dish* a;
public:
	set();
	set(int n);
	~set();
	void add(dish elem);
	void del(dish elem);
	int check_in(dish elem);
	dish* mass();
	int lenth() {
		return size;
	}
	set operator+ (const set& set1);
	set operator* (const set& set1);
	set& operator= (const set& set1);
	friend istream& operator>> (istream& in, const set& set);
	friend ostream& operator<< (ostream& out, const set& set);
	set(const set& set);
	set operator- (const set& set1);
};


set::set() {
	size = 0;
	a = nullptr;
}

 set ::set(int n) {
	a = new dish[n];
	size = n;
}

 set :: ~set() {
	delete[] a;
	a = nullptr;
	size = 0;
}

 
int set::check_in(dish elem) {
	for (int i = 0; i < size; ++i) {
		if (a[i] == elem) {
			return 1;
		}
	}
	return 0;
}

 
void set ::add(dish elem) {
	if (!(*this).check_in(elem)) {
		++size;
		dish* dop = new dish[size];
		for (int i = 0; i < size - 1; ++i)
			dop[i] = a[i];
		dop[size - 1] = elem;
		delete[]a;
		a = dop;
	}
}

    
void set ::del(dish elem) {
	if ((*this).check_in(elem)) {
		--size;
		dish* dop = new dish[size];
		int i;
		for (i = 0; i < size + 1; ++i) {
			if (a[i] == elem)
				break;
			dop[i] = a[i];
		}
		for (i += 1; i < size + 1; ++i)
			dop[i - 1] = a[i];
		delete[] a;
		a = dop;
	}
}

 
dish* set::mass() {
	return (this->a);
}


 
set set:: operator*(const set& set1) {
	set inter;
	for (int i = 0; i < set1.size; ++i)
		if (check_in(set1.a[i]))
			inter.add(set1.a[i]);
	return inter;
}

  
set set:: operator+ (const set& set1) {
	set unions(*this);
	for (int i = 0; i < set1.size; ++i)
		unions.add(set1.a[i]);
	return unions;
}

 
set set:: operator- (const set& set1) {
	set lit(*this);
	for (int i = 0; i < set1.size; ++i)
		lit.del(set1.a[i]);
	return lit;
}

 
set& set:: operator= (const set& set1) {
	this->size = set1.size;
	if (this->a != nullptr)
		delete[] this->a;
	this->a = new dish[set1.size];
	for (int i = 0; i < set1.size; ++i)
		this->a[i] = set1.a[i];
	return *this;
}


istream& operator>> (istream& in, const set& set) {
	cout << "Введите сначала название блюда, а затем его стоимость ";
	for (int i = 0; i < set.size; ++i)
		in >> set.a[i];
	return in;
}


ostream& operator<< (ostream& out, const set& set) {
	if (set.a == nullptr)
		cout << "Пусто" << endl;
	else {
		for (int i = 0; i < set.size; ++i)
			out << "Номер блюда — " << i + 1 << " " << set.a[i] << endl;
	}
	return out;
}


set::set(const set& set) {
	size = set.size;
	if (size == 0)
		a = nullptr;
	else
	{
		a = new dish[size];
		for (int i = 0; i < size; i++)
			a[i] = set.a[i];
	}
}

/* Известно, что меню ресторана содержи к - фирменных блюд,
Каждое блюдо характеризуется номером из числа К, названием
и стоимостью.В течении дня были обслужены N посетителей,
каждый из которых заказал какие - то 3 фирменных
блюда(множество) и заплатил за эти блюда некоторую сумму
денег.Напечатать список блюд и их стоимость, которые,
заказали все посетители, и список блюд которые не заказал
ни один посетитель.*/




int main() {

	cout << "Введите число предлагаемых блюд: ";
	int size;
	cin >> size;
	set menu(size);
	cin >> menu;
	cout << menu << endl;

	cout << "Сколько посетителей? >>>  ";
	int n;
	cin >> n;

	set all = menu; // заказали все посетители
	set each; // все заказанные блюда
	cout << "Введите номер блюда из меню " << endl;
	int i = 1;
	do {
		set order;
		cout << "Заказ номер  " << i << endl;
		int nom;
		for (int j = 1; j < 4; ++j) {
			cin >> nom;
			order.add(menu.mass()[nom - 1]);
		}
		all = all * order;
		each = each + order;
		++i;
	} while (i < n + 1);

	cout << "Каждый заказал "  << endl << all << endl;

	cout << "Никто не заказал:  " << endl << menu - each;

	return 0;
}