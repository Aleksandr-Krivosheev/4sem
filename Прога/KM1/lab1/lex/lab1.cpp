// lab1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <math.h>
using namespace std;

template <class A>
float schet(A **X, int k, int n)
{
    float nul = 0;
    for (int i = 0; i < n; i++)
    {
        if (X[k][i] == 0)
            nul++;
    }
    return (nul);
}

class complex
{
    double x, y;

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

    friend std::ostream &operator<<(std::ostream &out, const complex &A);
    friend std::istream &operator>>(std::istream &in, complex &A);
    complex &operator-(complex &A)
    {
        this->x = this->x - A.x;
        this->y = this->y - A.y;
        return *this;
    }
    complex &operator=(complex &A)
    {
        this->x = A.x;
        this->y = A.y;
        return *this;
    }

    bool operator<(complex &A)
    {
        if ((this->x * this->x + this->y * this->y) < (A.x * A.x + A.y * A.y))
            return true;
        else
            return false;
    }

    bool operator==(int a)
    {
        if ((this->x == a) && (this->y == a))
            return true;
        else
            return false;
    }
};

std::istream &operator>>(std::istream &in, complex &A)
{
    printf("введите действительную часть: ");
    in >> A.x;
    printf("введите мнимую часть: ");
    in >> A.y;

    return in;
}

std::ostream &operator<<(std::ostream &out, const complex &A)
{
    if (A.y >= 0)
        out << A.x << "+" << A.y << "i";
    else
        out << A.x << A.y << "i";
    return out;
}

int main()
{

    complex **X;
    int n;

    float **A;

    cout << "Введите размер матрицы nXn\nn = ";
    cin >> n;

    A = new float *[n];
    /* X = new complex* [n]; */
    for (int i = 0; i < n; i++)
        /* X[i] = new complex[n]; */
        A[i] = new float[n];

    cout << "Введите элементы матрицы" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            /* cin >> X[i][j]; */
            cin >> A[i][j];

    cout << "получившаяся матрица:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            /*  cout << X[i][j] << ' '; */
            cout << A[i][j] << ' ';
        cout << endl;
    }

    float *B;
    B = new float[n];

    for (int i = 0; i < n; i++)
        B[i] = schet(A, i, n);

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
