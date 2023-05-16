#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
template <class T>
class complex
{
    T image, real;

public:
    complex(T a = T(0), T b = T(0))
    {
        image = a;
        real = b;
    }
    complex<T> operator+(complex<T> z)
    {
        image = image + z.image;
        real = real + z.real;
        return (*this);
    }
    //если в функции переменная параметризованного класса, то для класса указывается
    //параметр
    complex<T> assign(T a, T b)
    {
        image = a;
        real = b;
    }
     //формирует компл.число
    void print()
    {
        cout << "complex= " << real << " + " << image << "*i" << endl;
    }
    complex<T> &operator=(complex<T> z)
    {
        real = z.real;
        image = z.image;
        return (*this);
    }
    complex<T> add(complex<T> z1, complex<T> z2)
    {
        this->real = z1.real + z2.real;
        this->image = z1.imag + z2.image;
        return (*this);
    }
    T GetRe() { return real; }
    T Getim() { return image; }
    //конец описания класса
};

int main(void)
{
    complex<int> A, B,C, O1, c1;
    A.print();
    complex<float> r(1.2, 2.3), r1(2.5, -0.4), r2;
    r.print();
    C = A + (B);
    C.print();
    r2 = r + (r1);
    cout << "float" << endl;
    r2.print();
    cout << "sozdanie\n";
    c1.assign(5, 5);
    c1.print();
    A.print();
    cout << "result" << endl;
    c1 + A;
    O1 = c1;
    O1.print();
    return 0;
}