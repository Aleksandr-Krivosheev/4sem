#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
	vector<double> mas;
	vector<double>::iterator it;
	int A = 0, B = 0, n = 0, el = 0;

	cout << "Введите размер массива: " << endl;
	cin >> n;

	cout << "Введите массив чисел: " << endl;
	for (int i = 0; i < n; i++)
	{
		cin >> el;
		mas.push_back(el);
	}

	cout << "Введите диапазон чисел : " << endl;
	cin >> A >> B;

	for (it = mas.begin(); it != mas.end(); it++)
	{
		if ((*it < A) || (*it > B))
		{
			cout << "Элемент, попадающий в диапазон нет" << endl;
			cout << "Его номер: " << it - mas.begin() + 1 << endl;
			return 0;
		}
	}
	cout << "Элемента, попадающего в диапазон нет" << endl;
	return 0;
}