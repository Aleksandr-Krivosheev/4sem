#include <iostream>
using namespace std;

template <class T>
class complex;

template <class T>
std::ostream &operator<<(std::ostream &out, const complex<T> &A)
{
    if (A.y >= 0)
        out << A.x << "+" << A.y << "i";
    else
        out << A.x << A.y << "i";
    return out;
}

template <class T>
std::istream &operator>>(std::istream &in, complex<T> &A)
{
    cout<<("введите действительную часть: ");
    in >> A.x;
    cout<<("введите мнимую часть: ");
    in >> A.y;
    return in;
}

template <class T>
class complex
{
    T x, y;

public:
    complex()
    {
        x = 0;
        y = 0;
    }
    complex(T a, T b)
    {
        x = a;
        y = b;
    }
    friend std::ostream &operator<<<T>(std::ostream &out, const complex &A);
    friend std::istream &operator>><T>(std::istream &in, complex &A);
};


int main()
{
    complex<double> A2,A3(3,4);
    cin >> A2;
    cout << A2;
    cout << A3;
}