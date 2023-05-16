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
    printf("введите действительную часть: ");
    in >> A.x;
    printf("введите мнимую часть: ");
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
    complex(double a, double b)
    {
        x = a;
        y = b;
    }

    complex &operator=(complex &A)
    {
        x = A.x;
        y = A.y;
        return (*this);
    }

    bool operator==(int a)
    {
        if ((this->x == a) && (this->y == a))
            return true;
        else
            return false;
    }

    friend std::ostream &operator<<<T>(std::ostream &out, const complex &A);
    friend std::istream &operator>><T>(std::istream &in, complex &A);
};

template <class A>
void gg(A **x, int *b, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        int s = 0;
        for (int j = 0; j < m; j++)
        {
            if (x[i][j] == 0)
            {
                s++;
            }
        }
        b[i] = s;
    }
}

template <class tupe>
void vot(tupe **X, int *b)
{

    int n, m;
    cout << "Введите размер матрицы nXm\nn = ";
    cin >> n;
    try
    {
        if (n <= 0)
        {
            throw n;
        }
    }
    catch (const int a)
    {
        if (a == 0)
            cout << "равен 0" << endl;
        else if (a <= 0)
        {
            cout << " отрицательный n" << endl;
        }
    }
    cout << "m = ";
    cin >> m;
    try
    {
        if (m <= 0)
        {
            throw m;
        }
        else
        {
    X = new tupe *[n];
    for (int i = 0; i < n; i++)
    {
        X[i] = new tupe[n];
    }
    cout << "Введите элементы матрицы" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i][j];
        }
    }

        }
    }
    catch (const int a)
    {
        if (a == 0)
            cout << "равен 0" << endl;
        else if (a <= 0)
        {
            cout << " отрицательный m" << endl;
        }
    }
    X = new tupe *[n];
    for (int i = 0; i < n; i++)
    {
        X[i] = new tupe[n];
    }
    cout << "Введите элементы матрицы" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> X[i][j];
        }
    }

    cout << "Mатрица:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << X[i][j] << ' ';
        }
        cout << endl;
    }
    b = new int[n];
    gg(X, b, n, m);
    cout << "Одномерный масив:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << b[i] << " ";
    }
    cout << endl;
}

int main()
{
    int **A;
    int *B;
    vot(A, B);

    float **A1;
    int *B1;
    vot(A1, B1);

    complex<double> **A2;
    int *B2;
    vot(A2, B2);
}