#include <iostream>
#include <string.h>
#include <typeinfo>
using namespace std;
class point
{
    int x, y;

public:
    point(int a = 0, int b = 0)
    {
        x = a;
        y = b;
    }
    point(const point &ob)
    {
        x = ob.x;
        y = ob.y;
    }
    point &operator=(const point &ob)
    {
        x = ob.x;
        y = ob.y;
        return (*this);
    }
};

template <class T>
class Myclass
{
protected:
    T value;

public:
    Myclass(T value1) { value = value1; }
    void DataTypeSize() { cout << "razmer =" << sizeof(value) << endl; }
};
// наследование шаблона от шаблона
template <class T>
class TypeInfo : public Myclass<T>
{
public:
    TypeInfo(T value1) : Myclass<T>(value1){};
    void ShowTypeName()
    {
        cout << "imj tipa" << endl;
        cout << typeid(Myclass<T>::value).name() << endl;
    }
};
int main(void)
{
    int a = 5;
    TypeInfo<int> c(a);
    c.DataTypeSize();
    c.ShowTypeName();
    double f = 5.345;
    TypeInfo<double> c1(f);
    c1.DataTypeSize();
    c1.ShowTypeName();
    point p(10, 10);
    TypeInfo<point> c2(p);
    c2.DataTypeSize();
    c2.ShowTypeName();
    return 0;
}