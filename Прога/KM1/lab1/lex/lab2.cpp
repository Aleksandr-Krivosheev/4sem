// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;

template <class T>
class complex;

template <class A>
float schet(A** X, int k, int n)
{
    A min;
    for (int i = 0; i < n; i++)
    {
        min = X[k][0];
        if (X[k][i] < min)
            min = X[k][i];
    }
    A C;
    C = X[k][k] - min;
    return (abs(C));
}

template<class T>
ostream& operator<< (std::ostream& out, const complex <T>& A)
{
    if (A.y >= 0)
        out << A.x << "+" << A.y << "i";
    else
        out << A.x << A.y << "i";

    return out;
}

template <class T>
istream& operator>> (std::istream& in, complex <T>& A)
{
    printf("введите действительную часть: ");
    in >> A.x;
    printf("введите мнимую часть: ");
    in >> A.y;

    return in;
}


template < class T>
class complex {
    T x, y;
public:
    complex()
    {
        x = 0;
        y = 0;
    }
    complex(double a, double b)
    {
        x = a;
        y = b;
    }
    double module()
    {
        return (sqrt(pow(x, 2) + pow(y, 2)));
    }
    float abs()
    {
        return (sqrt(x * x + y * y));
    }


    friend ostream& operator<< <T> (std::ostream& out, const complex& A);
    friend istream& operator>> <T>(std::istream& in, complex& A);

    complex<T>& operator- (complex<T>& A)
    {
        this->x = this->x - A.x;
        this->y = this->y - A.y;
        return *this;
    }
    complex<T>& operator= (complex<T>& A)
    {
        this->x = A.x;
        this->y = A.y;
        return *this;
    }

    bool operator< (complex<T>& A)
    {
        if ((this->x * this->x + this->y * this->y) < (A.x * A.x + A.y * A.y))
            return true;
        else
            return false;
    }
};

template <class T>
float abs(complex<T> X)
{
    return X.abs();
}

int main()
{

    complex<double>** X;
    int n;

    cout << "Введите размер матрицы nXn\nn = ";

    //int** A;

    try
    {
        cin >> n;
        if (n < 1)
            throw 1;
        else
            throw 0;
    }
    catch (const int a)
    {
        if (a == 1)
        {
            cout << "Неверный ввод"<<endl;
            return 0;
        }
    }

    //A = new int* [n];
    X = new complex<double> * [n];
    for (int i = 0; i < n; i++)
        X[i] = new complex<double>[n];
    //A[i] = new int[n];

    cout << "Введите элементы матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> X[i][j];
    //cin >> A[i][j];

    cout << "получившаяся матрица:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << X[i][j] << ' ';
        //cout << A[i][j] << ' ';
        cout << endl;
    }


    float* B;
    B = new float[n];

    for (int i = 0; i < n; i++)
        B[i] = schet(X, i, n);

    cout << "\nПолучившийся массив: " << endl;
    for (int i = 0; i < n; i++)
        cout << B[i] << ' ';
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
