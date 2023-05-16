// lab1.cpp : Этот файл// lab2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include <math.h>
#include <iomanip> // для установки ширины текста
using namespace std;

template <class T>
class complex;


template <class T>
ostream &operator<<(std::ostream &out, const complex<T> &A)
{
    if (A.y >= 0)
        out << A.x << "+" << A.y << "i";
    else
        out << A.x << A.y << "i";

    return out;
}

template <class T>
istream &operator>>(std::istream &in, complex<T> &A)
{
    printf_s("\nвведите действительную часть: ");
    in >> A.x;
    printf_s("введите мнимую часть: ");
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

    friend ostream &operator<<<T>(std::ostream &out, const complex &A);
    friend istream &operator>><T>(std::istream &in, complex &A);

    bool operator==(complex<T> A)
    {
        if ((this->x == A.x) && (this->y == A.y))
            return true;
        else
            return false;
    }

    int length()
    {
        int n = 1;
        T k = y;
        while ((k / 10) >= 1)
        {
            k = k / 10;
            n++;
        }
        return n;
    }
};

template <class T>
class mnoz;

template <class T>
ostream &operator<<(std::ostream &out, const mnoz<T> &X)
{
    for (int i = 0; i < X.length; i++)
        printf_s("%4d   |", i + 1);
    cout << endl;
    for (int i = 0; i < X.length; i++)
        out << left << setw(7) << X.array[i] << "|";
    out << endl;
    return out;
}

template <class T>
istream &operator>>(std::istream &in, mnoz<T> &X)
{
    cout << "Введите значение элемента:\n";
    T a;
    cin >> a;
    bool flag = false;
    for (int i = 0; i < X.length; i++)
    {
        flag = false;
        if (a == X.array[i])
            flag = true;
    }
    if (flag == true)
        return in;
    else
    {
        X + a;
        return in;
    }
}

// перегрузка для комплексных
template <class T1>
ostream &operator<<(std::ostream &out, const mnoz<complex<T1>> &Y)
{
    for (int i = 0; i < Y.length; i++)
        printf_s("%7d   |", i + 1);
    cout << endl;
    int n;
    for (int i = 0; i < Y.length; i++)
    {
        out << right << setw(8 - Y.array[i].length()) << Y.array[i] << "|";
    }
    out << endl;
    return out;
}

template <class T>
class mnoz
{
    T *array;
    int length;

public:
    mnoz(int n = 0)
    {
        if (n != 0)
        {
            cout << "Введите элементы:\n";
            array = new T[n];
            T elem;
            bool flag = false;
            for (int i = 0; i < n; i++)
            {
                cin >> elem;
                flag = false;
                for (int j = 0; j < i + 1; j++)
                    if (elem == array[j])
                        flag = true;
                if (flag == false)
                {
                    array[length] = elem;
                    length++;
                }
            }
        }
    }

    ~mnoz()
    {
        delete[] array;
    }

    // добавление нового элемента
    void new_elem()
    {
        T x;
        cout << "Введите новый элемент: ";
        cin >> x;
        new_elem(x);
    }

    void new_elem(T x)
    {
        bool flag = false;
        for (int i = 0; i < length; i++)
        {
            flag = false;
            if (x == array[i])
                flag = true;
        }
        if (flag == false)
        {
            T *A;
            A = new T[length + 1];
            for (int i = 0; i < length; i++)
                A[i] = array[i];
            A[length] = x;
            length++;
            delete[] array;
            array = new T[length];
            for (int i = 0; i < length; i++)
                array[i] = A[i];
            delete[] A;
        }
    }

    // удаление элемента
    void delete_elem()
    {
        int k;
        cout << "Введите номер элемента, который надо удалить: ";
        cin >> k;
        T *A;
        A = new T[length - 1];
        for (int i = 0; i < k - 1; i++)
            A[i] = array[i];
        for (int i = k; i < length; i++)
            A[i - 1] = array[i];
        delete[] array;
        length--;
        array = new T[length];
        for (int i = 0; i < length; i++)
            array[i] = A[i];
        delete[] A;
    }

    // объединение
    void obedin(mnoz<T> &X)
    {
        for (int i = 0; i < X.length; i++)
            new_elem(X.array[i]);
    }

    // пересечение
    void peresech(mnoz<T> &X)
    {
        T *A;
        int NewLength = 0;
        A = new T[length + X.length]; // массив временный (в него будет суваться пересечение)
        bool flag = false;

        for (int i = 0; i < length; i++)
        {
            flag = false;
            for (int j = 0; j < X.length; j++)
            {
                if (array[i] == X.array[j])
                    flag = true;
            }
            if (flag == true)
            {
                A[NewLength] = array[i];
                NewLength++;
            }
        }

        delete[] array;
        length = NewLength;
        array = new T[length];
        for (int i = 0; i < length; i++)
            array[i] = A[i];
        delete[] A;
    }

    // проверка на вхождение
    bool checker(T a)
    {
        for (int i = 0; i < length; i++)
        {
            if (a == array[i])
                return true;
        }
        return false;
    }

    friend ostream &operator<<<T>(std::ostream &out, const mnoz<T> &X); // перегрузка cout <<
    friend istream &operator>><T>(std::istream &in, mnoz<T> &X);        // перегрузка cin >>

    template <class T1>
    friend ostream &operator<<<T>(std::ostream &out, const mnoz<complex<T1>> &Y);

    T operator=(mnoz<T> X)
    {
        this->length = X.length;
        delete[] this->array;
        this->array = new T[X.length];
        for (int i = 0; i < X.length; i++)
            this->array[i] = X.array[i];
        return *this;
    }

    void operator+(T X) // это короче шоб  писать так: X +5 и всё будет четка
    {
        T *A;
        A = new T[this->length + 1];
        for (int i = 0; i < this->length; i++)
        {
            A[i] = this->array[i];
        }
        A[this->length] = X;
        this->length++;
        delete[] this->array;
        this->array = new T[length];
        for (int i = 0; i < length; i++)
            this->array[i] = A[i];
        delete[] A;
    }
};

int main()
{

    mnoz<complex<float>> A;
    mnoz<complex<float>> B;

    char a = '9';
    while (a != '0')
    {
        cout << "1-добавление элемента в множество" << endl
             << "2-Удаление элемента из множества" << endl
             << "3-Объединение множеств" << endl
             << "4-Пересечение множеств" << endl
             << "5-Вхождение элемента в множество (проверка)" << endl
             << "6-вывод" << endl
             << "0-выход" << endl;
        cout << "\nВы выбираете: ";
        cin >> a;

        if (a == '1')
        {
            cout << "\nесть 2 множества, какое выбираете?(1/2): ";
            cin >> a;
            if (a == '1')
                A.new_elem();
            if (a == '2')
                B.new_elem();
            cout << endl;
        }
        else if (a == '2')
        {
            cout << "\nПервое множество: " << endl;
            cout << A;
            cout << "Второе множество: " << endl;
            cout << B;
            cout << "\nесть 2 множества, какое выбираете?(1/2): ";
            cin >> a;
            if (a == '1')
                A.delete_elem();
            if (a == '2')
                B.delete_elem();
            cout << endl;
        }
        else if (a == '3')
        {
            cout << "\nесть 2 множества, в какое записать объединение?(1/2): ";
            cin >> a;
            if (a == '1')
                A.obedin(B);
            if (a == '2')
                B.obedin(A);
            cout << endl;
        }
        else if (a == '4')
        {
            cout << "\nесть 2 множества, в какое записать пересечение?(1/2): ";
            cin >> a;
            if (a == '1')
                A.peresech(B);
            if (a == '2')
                B.peresech(A);
            cout << endl;
        }
        else if (a == '5')
        {
            complex<float> k;
            cout << "Введите значение для проверки: ";
            cin >> k;
            cout << "\nесть 2 множества, в каком проверить вхождение?(1/2): ";
            cin >> a;
            if (a == '1')
                if (A.checker(k) == true)
                    cout << "\nВходит в первое!\n";
                else
                    cout << "\nНе входит в первое(\n";
            if (a == '2')
                if (B.checker(k) == true)
                    cout << "\nВходит во второе!\n";
                else
                    cout << "\nНе входит во второе(\n";
            cout << endl;
        }
        else if (a == '6')
        {
            cout << "\nесть 2 множества, какое выбираете?(1/2): ";
            cin >> a;
            if (a == '1')
                cout << A;
            if (a == '2')
                cout << B;
            getchar();
            getchar();
            cout << endl;
        }
    }
}