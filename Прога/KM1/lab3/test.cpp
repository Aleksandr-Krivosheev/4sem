#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

using namespace std;
class base;
class car;

class car
{
public:
    string brand, num;
    int cost;
};

class base : public car
{
public:
    car *a;
    int size;

public:
    base(int s) //конструктор
    {
        size = s;
        a = new car[size];
        for (int i = 0; i < size; i++)
        {
            a[i].num = " ";
            a[i].brand = " ";
            a[i].cost = 0;
        }
    }
    ~base() //деструктор
    {
        delete[] a;
    }
    void assign()
    {
        cout << "Введите машины" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << "номер: ";
            cin >> a[i].num;
            cout << "марка: ";
            cin >> a[i].brand;
            cout << "цена: ";
            cin >> a[i].cost;
        }
    }
    void print()
    {
        cout << "Введённое множество ";
        for (int i = 0; i < size; i++)
            cout << a[i].num << " " << a[i].brand << " " << a[i].cost << endl;
    }
    bool operator==(base &x)
    {
        bool ch = true;
        int k = 0, l = 0;
        int i, j = 0;
        string s1 = "", s2 = "";
        while (i < size && ch)
        {
            if (a[i].brand == "КАМАЗ")
            {
                s1 += "КАМАЗ";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < size && ch)
        {
            if (a[i].brand == "БеЛАЗ")
            {
                s1 += "БеЛАЗ";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < size && ch)
        {
            if (a[i].brand == "ГАЗ-24")
            {
                s1 += "ГАЗ-24";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < size && ch)
        {
            if (a[i].brand == "Икарус")
            {
                s1 += "Икарус";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < size && ch)
        {
            if (a[i].brand == "ЛИАЗ")
            {
                s1 += "ЛИАЗ";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < size && ch)
        {
            if (a[i].brand == "РАФ")
            {
                s1 += "РАФ";
                ch = false;
            }
            i++;
        }
        while (i < x.size && ch)
        {
            if (x.a[i].brand == "КАМАЗ")
            {
                s2 += "КАМАЗ";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < x.size && ch)
        {
            if (x.a[i].brand == "БеЛАЗ")
            {
                s2 += "БеЛАЗ";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < x.size && ch)
        {
            if (x.a[i].brand == "ГАЗ-24")
            {
                s2 += "ГАЗ-24";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < x.size && ch)
        {
            if (x.a[i].brand == "Икарус")
            {
                s2 += "Икарус";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < x.size && ch)
        {
            if (x.a[i].brand == "ЛИАЗ")
            {
                s2 += "ЛИАЗ";
                ch = false;
            }
            i++;
        }
        i = 0;
        ch = true;
        while (i < x.size && ch)
        {
            if (x.a[i].brand == "РАФ")
            {
                s2 += "РАФ";
                ch = false;
            }
            i++;
        }
        if (s1 == s2)
        {
            return true;
        }
        else
            return false;
    }
    int cost_num(base &x)
    {
        int cost1 = 0, cost2 = 0;
        for (int i = 0; i < size; i++)
        {
            cost1 += a[i].cost;
        }
        for (int i = 0; i < x.size; i++)
        {
            cost2 += x.a[i].cost;
        }
        return cost1 + cost2;
    }
    //Перегрузить в шаблоне класса ввод-вывод  множества на стандартный ввод-вывод
    friend ostream &operator<<(ostream &out, const base &s);
    friend istream &operator>>(istream &in, base &s);
};

ostream &operator<<(ostream &out, const base &s)
{
    cout << "Машины автобазы: " << endl;
    {
        for (int i = 0; i < s.size; i++)
        {
            out << s.a[i].num << " " << s.a[i].brand << " " << s.a[i].cost << endl;
        }
        cout << endl;
        return (out);
    }
}
istream &operator>>(istream &in, base &s)
{
    cout << "Введите машины" << endl;
    for (int i = 0; i < s.size; i++)
    {
        cout << "номер: ";
        in >> s.a[i].num;
        cout << "марка: ";
        in >> s.a[i].brand;
        cout << "цена: ";
        in >> s.a[i].cost;
    }
    return (in);
}

int main(void)
{
    int main_cost;
    int s = 3;
    int count1, count2, count3;
    cout << "Количество автобаз: " << s << endl;
    cout << "Количество машин первой автобазы: ";
    cin >> count1;
    base base1(count1);
    cin >> base1;
    cout << "Количество машин второй автобазы: ";
    cin >> count2;
    base base2(count2);
    cin >> base2;
    cout << "Количество машин третьей автобазы: ";
    cin >> count3;
    base base3(count3);
    cin >> base3;
    cout << base1;
    cout << base2;
    cout << base3;
    if (base1 == base2)
    {
        cout << "набор марок совпадает у 1 и 2 автобазы" << endl;
        cout << "марки: ";
        for (int i = 0; i < base1.size; i++)
        {
            cout << base1.a[i].brand << " ";
        }
        cout << endl;
        main_cost = base1.cost_num(base2);
        cout << "Общая стоимость = " << main_cost << endl;
        ;
    }
    if (base1 == base3)
    {
        cout << "набор марок совпадает у 1 и 3 автобазы" << endl;
        cout << "марки: ";
        for (int i = 0; i < base1.size; i++)
        {
            cout << base1.a[i].brand << " ";
        }
        cout << endl;
        main_cost = base1.cost_num(base3);
        cout << "Общая стоимость = " << main_cost << endl;
        ;
    }
    if (base2 == base3)
    {
        cout << "набор марок совпадает у 2 и 3 автобазы" << endl;
        cout << "марки: ";
        for (int i = 0; i < base2.size; i++)
        {
            cout << base2.a[i].brand << " ";
        }
        cout << endl;
        main_cost = base2.cost_num(base3);
        cout << "Общая стоимость = " << main_cost << endl;
        ;
    }

    system("pause");
    return 0;
}