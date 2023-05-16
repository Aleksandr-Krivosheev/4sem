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

    complex &operator=(T a)
    {
        x = a;
        y = a;
        return (*this);
    }

    bool operator==(complex<T> A)
    {
        if ((this->x == A.x) && (this->y == A.y))
            return true;
        else
            return false;
    }

    bool operator==(T a)
    {
        if ((this->x == a) && (this->y == a))
            return true;
        else
            return false;
    }

    friend std::ostream &operator<<<T>(std::ostream &out, const complex &A);
    friend std::istream &operator>><T>(std::istream &in, complex &A);
};

template <class T>
class mnoz;

template <class T>
std::ostream &operator<<(std::ostream &out, const mnoz<T> &X)
{
    if (X.size == 0)
    {
        cout << "{}";
        return out;
    }
    cout << "{" << X.a[0];
    for (int i = 1; i < X.size; i++)
    {
        cout << ", " << X.a[i];
    }
    cout << "}";
    return out;
}

template <class T>
std::istream &operator>>(std::istream &in, mnoz<T> &X)
{
    T x;
    cout << "Введите новый элемент: ";
    in >> x;
    if (X.size < X.msize)
    {
        if (!X.check_in(x))
        {
            X.a[X.size] = x;
            X.size = X.size + 1;
            cout << ("Добавление прошло успешно");
        }
        else
            cout << ("Добавление невозможно");
    }
    else
        cout << ("Добавление невозможно");
    return in;
}

template <class T>
class mnoz
{
private:
    T *a;
    int size, msize;

public:
    mnoz(int maxim) // конструктор
    {
        a = new T[maxim];
        for (int i = 0; i < maxim; i++)
            a[i] = 0;
        msize = maxim;
        size = 0;
    }
    mnoz(mnoz<T> &x)
    {
        msize = x.msize;
        a = new T[msize];
        for (int i = 0; i < msize; i++)
            a[i] = x.a[i];
    }
    ~mnoz() // диструктор
    {
        delete[] a;
    }

    void add() //добавление эл-та в множество
    {
        T x;
        cout << "Введите новый элемент: ";
        //cin >> x;
        x = system("seq 1");
        add(x);
    }

    void add(T x) //добавление эл-та в множество
    {
        if (size < msize)
        {
            if (!check_in(x))
            {
                a[size] = x;
                size = size + 1;
                cout << ("Добавление прошло успешно");
            }
            else
                cout << ("Добавление невозможно");
        }
        else
            cout << ("Добавление невозможно");
    }

    void del() //удаление эл-та из множества
    {
        T x;
        cin >> x;
        bool flag = 0;
        if (size != 0)
        {
            for (int i = 0; i < size; i++)
            {
                if (a[i] == x)
                {
                    for (int j = i; j < size; j++)
                    {
                        a[j] = a[j + 1];
                    }
                    size = size - 1;
                    flag = 1;
                }
            }
            if (flag == 1)
                cout << ("Удаление прошло успешно");
        }
        else(flag == 0);
            cout << ("Удаление невозможно");
    }

    bool check_in(T x) //проверка вхождения эл-та в множество
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i] == x)
            {
                return true;
            }
        }
        return false;
    }

    void proverka()
    {
        T x;
        cin >> x;
        if (check_in(x))
            cout << ("Элемент содержится в данном множестве");
        else
            cout << ("Элемент не содержится в данном множестве");
    }

    void output() //Вывод множества на экран
    {
        if (size == 0)
        {
            cout << "{}";
            return;
        }
        cout << "{" << a[0];
        for (int i = 1; i < size; i++)
        {
            cout << ", " << a[i];
        }
        cout << "}";
    }

    mnoz<T> operator=(const mnoz<T> &s) 
    {
        if (this == &s)
            return *this;
        if (msize != s.msize)
        {
            delete a;
            a = new T[s.msize];
            size = 0;
            msize = s.msize;
        }
        for (int i = 0; i < msize; i++)
        {
            a[i] = s.a[i];
        }
        size = s.size;
        return *this;
    }

    mnoz<T> operator*(const mnoz<T> &s2) 
    {
        int x = 0;
        mnoz<T> s3(msize);
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < s2.size; j++)
            {
                if (s2.a[j] == a[i])
                {
                    s3.a[x] = a[i];
                    x++;
                    s3.size = s3.size + 1;
                }
            }
        }
        return s3;
    }

    mnoz<T> operator&(const mnoz<T> &s2) 
    {
        bool in;
        mnoz<T> s3(size + s2.size);
        for (int i = 0; i < size; i++)
        {
            s3.a[i] = a[i];
            s3.size += 1;
        }
        for (int i = 0; i < s2.size; i++)
        {
            in = s3.check_in(s2.a[i]);
            if (!in)
            {
                s3.a[size] = s2.a[i];
                s3.size += 1;
            }
        }
        return s3;
    }

    friend std::ostream &operator<<<T>(std::ostream &out, const mnoz &A);
    friend std::istream &operator>><T>(std::istream &in, mnoz &A);
};

int main()
{
    int n = 9;
    char choose;
    int max, x;
    system("date");
    cout << ("Введите максимальный размер множества-");
    cin >> max;
    mnoz<int> set1(max);
    mnoz<int> set2(max);
    mnoz<int> set3(max * max);
    while (n != 0)
    {
        cout << '\n'
             << " ------------Menu------------ "
             << '\n'
             << ("1. Добавление эл-та в множество")
             << '\n'
             << ("2. Удаление эл-та из множества")
             << '\n'
             << ("3. Проверка вхождения эл-та в множество")
             << '\n'
             << ("4. Присвоение одного множества другому")
             << '\n'
             << ("5. Пересечение двух множеств")
             << '\n'
             << ("6. Объединение двух множеств")
             << '\n'
             << ("7. Вывод множества на экран")
             << '\n'
             << ("0. Выход")
             << '\n'
             << "<";
        cin >> n;
        getchar();
        if (n == 1)
        {
            cout << ("Выберете множество для добавления(1/2)");
            cin >> choose;
            if (choose == '1')
                cin >> set1;
            // set1.add();
            if (choose == '2')
                set2.add();
            getchar();
        }
        else if (n == 2)
        {
            cout << ("Выберете множество для удаления(1/2)");
            cin >> choose;
            cout << ("Введите величину эл-та: ");
            if (choose == '1')
            {
                set1.del();
                set1.output();
            }
            if (choose == '2')
            {
                set2.del();
            }
            getchar();
        }
        else if (n == 3)
        {
            cout << ("Выберете множество для проверки(1/2)");
            cin >> choose;
            cout << ("Введите величину эл-та: ");
            if (choose == '1')
            {
                set1.proverka();
            }
            if (choose == '2')
            {
                set2.proverka();
            }
        }
        else if (n == 4)
        {
            cout << ("Выберете в какое множество копировать(1/2)");
            cin >> choose;
            if (choose == '1')
                set1 = set2;
            if (choose == '2')
                set2 = set1;
        }
        else if (n == 5)
        {
            set3 = set1 * set2;
            cout << ("Результат записан в 3е множество");
            cout << endl;
            set3.output();
        }
        else if (n == 6)
        {
            set3 = set1 & set2;
            cout << ("Результат записан в 3е множество");
            cout << endl;
            set3.output();
        }
        else if (n == 7)
        {
            cout << ("Выберите множество для вывода(1/2/3)\n");
            cin >> choose;
            if (choose == '1')
                cout << set1;
            // set1.output();
            if (choose == '2')
                set2.output();
            if (choose == '3')
                set3.output();
        }
    }
}