#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;

class point;
template <class T>
class Myclass;
// дружеств.функция становится параметризованной!!
template <class T>
void DataTypeSize(Myclass<T> &ob)
{
    cout << "razmer=" << sizeof(ob) << endl;
}
//программа выдает размеры всех типов
//пользовательский тип point
class point
{
    double x, y;

public:
    point(double a = 0, double b = 0) : x(a), y(b) {}
    //опережающие прототипы класса и функции
    template <class T> // для класса
    class Myclass;
    template <class T> // для функции
    void DataTypeSize(Myclass<T> &ob);
};
template <class T>
class Myclass
{
    T value;

public:
    Myclass(T value1) : value(value1){};
    //описание функции в параметризованном классе
    Myclass<T> &operator=(Myclass<T> &ob)
    {
        value = ob.value;
        return (*this);
    }
    //описание дружественной функции в параметризованном классе
    friend void DataTypeSize<T>(Myclass<T> &ob);
};

int main(void)
{
    int a = 5;
    Myclass<int> c(a);
    cout << "int" << endl;
    DataTypeSize(c);
    double f = 5.345;
    Myclass<double> c1(f);
    cout << "double" << endl;
    DataTypeSize(c1);
    point p(4.2, 10.5);
    Myclass<point> c2(p);
    cout << "point" << endl;
    DataTypeSize(c2);
    return 0;
}