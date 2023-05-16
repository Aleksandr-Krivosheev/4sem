#include <iostream>
#include <string>
using namespace std;
class mnoz;
class somolet;

class somolet
{
public:
    string name, marka;
    int mesta;
    string aeroport;
};

class mnoz : public somolet
{
public:
    int size, msize;
    somolet *a;

public:
    mnoz(int maxim) // конструктор
    {
        a = new somolet[maxim];
        for (int i = 0; i < maxim; i++)
        {
            a[i].aeroport = " ";
            a[i].name = " ";
            a[i].marka = " ";
            a[i].mesta = 0;
        }
        msize = maxim;
        size = maxim;
    }

    void add()
    {
        cout << "Введите информацию о самалете: " << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "Аеропорт N: ";
            cin >> a[i].aeroport;
            cout << "Название: ";
            cin >> a[i].name;
            cout << "Марка: ";
            cin >> a[i].marka;
            cout << "Число посадочных мест: ";
            cin >> a[i].mesta;
            cout << endl;
        }
    }
/*     int proverka()
    {
        for (int i = 0; i < size; i++)
        {
            if (a[i].aeroport)
        }
    } */

    ~mnoz() // диструктор
    {
        delete[] a;
    }

    friend std::ostream &operator<<(std::ostream &out, const mnoz &A);
    friend std::istream &operator>>(std::istream &in, mnoz &A);
};

std::ostream &operator<<(std::ostream &out, const mnoz &X)
{
    cout << "Информация: " << endl;
    for (int i = 0; i < X.size; i++)
    {
        out << " Aэропорт: "
            << X.a[i].aeroport
            << ", Название: "
            << X.a[i].name
            << ", Марка: "
            << X.a[i].marka
            << ", Число посадочных мест: "
            << X.a[i].mesta
            << endl;
    }
    cout << endl;
    return out;
}

std::istream &operator>>(std::istream &in, mnoz &X)
{
    cout << "Введите информацию о самалете: " << endl;
    for (int i = 0; i < X.size; i++)
    {
        cout << "Аеропорт N: ";
        in >> X.a[i].aeroport;
        cout << "Название: ";
        in >> X.a[i].name;
        cout << "Марка: ";
        in >> X.a[i].marka;
        cout << "Число посадочных мест: ";
        in >> X.a[i].mesta;
        cout << endl;
    }
    return in;
}

int main()
{
    char choose;
    int max, x;
    int n;
    cout << " кол-во:";
    cin >> n;
    mnoz<somolet> *s;
    // set = new char *[n];

    /*  cout << ("Введите максимальный размер множества-");
     cin >> max;
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
                 //cin >> set1;
                 //set1.add();
             if (choose == '2')
             //    set2.add();
             getchar();
         }
         else if (n == 2)
         {
             cout << ("Выберете множество для удаления(1/2)");
             cin >> choose;
             cout << ("Введите величину эл-та: ");
             if (choose == '1')
             {
                 //set1.del();
                 //set1.output();
             }
             if (choose == '2')
             {
                // set2.del();
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
               //  set1.proverka();
             }
             if (choose == '2')
             {
               //  set2.proverka();
             }
         }
         else if (n == 4)
         {
             cout << ("Выберете в какое множество копировать(1/2)");
             cin >> choose;
             if (choose == '1')
               //  set1 = set2;
             if (choose == '2')
                // set2 = set1;
         }
         else if (n == 5)
         {
            // set3 = set1 * set2;
             cout << ("Результат записан в 3е множество");
             cout << endl;
            // set3.output();
         }
         else if (n == 6)
         {
            // set3 = set1 & set2;
             cout << ("Результат записан в 3е множество");
             cout << endl;
           //  set3.output();
         }
         else if (n == 7)
         {
             cout << ("Выберите множество для вывода(1/2/3)\n");
             cin >> choose;
             if (choose == '1')
            //     cout << set1;
                 //set1.output();
             if (choose == '2')
            //     set2.output();
             if (choose == '3')
            //     set3.output();
         }
     } */
}