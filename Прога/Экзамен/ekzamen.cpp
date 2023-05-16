/* Создать шаблон возведения в степень. Класс содержит два поля степень и возводимое в степень данное.
Для простоты степень целая. Проверить работу на типах int, complex. Для типа char предусмотреть
особый случай, считая, что возведение в степень добавляет очередной символ справа. Для компл. числа
в степень возводим модуль комлпексного числа.*/

#include <iostream>
#include <math.h>
using namespace std;
class complex
{
    double real, img;

public:
    complex(double x = 0, double y = 0)
    {
        real = x;
        img = y;
    };

    void Input(double a, double b)
    {
        real = a;
        img = b;
    }

    double mod(complex a)
    {
        return (sqrt(a.real * a.real + a.img * a.img));
    }

    friend ostream &operator<<(ostream &out, const complex &a);
    friend istream &operator>>(istream &in, complex &a);
    
    complex operator*(complex &c1)
    {
        return c1.mod(c1) * c1.mod(c1);
    }
};

ostream &operator<<(ostream &out, const complex &a) // перегрузка вывода компл. числа
{
    if (a.img < 0)
        out << a.real << " " << a.img << "i ";
    else
        out << a.real << " + " << a.img << "i ";
    return out;
}

istream &operator>>(istream &in, complex &a) // перегрузка ввода компл. числа
{
    cout << "Действ. часть компл. числа = ";
    in >> a.real;
    cout << "Мнимания часть компл. числа = ";
    in >> a.img;
    return in;
}

/* complex &complex::operator*(complex &c1)
{
    return c1.mod(c1) * c1.mod(c1);
} */



template <typename T>
class powe
{
    int step;
    T num;

public:
    T pow();
    T pow(int s, T n);
};

template <typename T>
T powe<T>::pow(int s, T n)
{
    for (int i = 0; i < s; i++)
    {
        n = n * n;
    }
}

char powe<char>::pow() {}

int main()
{
    int elem;
    cout << "Введите число ";
    cin >> elem;
    cout << endl;
    cout << "Ваше число: " << elem << endl
         << endl;
    powe<int> P;
    P.pow(3,elem);

    powe<complex> D;
    D.pow(3,elem);
}
