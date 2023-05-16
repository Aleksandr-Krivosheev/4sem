﻿#include <iostream>
#include <conio.h>

using namespace std;

class plane
{
    string model;
    int pasnum;

public:
    void setp()
    {
        cout << "Введите модель самолёта" << endl;
        cin >> model;
        cout << "Введите число посадочных мест" << endl;
        cin >> pasnum;
    }

    string getm()
    {
        return model;
    }

    int getpn()
    {
        return pasnum;
    }

    friend ostream &operator<<(ostream &out, const plane &x);
};

ostream &operator<<(ostream &out, const plane &x)
{
    out << "Модель: " << x.model << "   "
        << "Число посадочных мест: " << x.pasnum << endl;
    return out;
};

class mnosh
{
    plane *ptr;
    int size;

public:
    mnosh()
    {
        cout << "Введите кол-во самолётов" << endl;
        cin >> size;

        ptr = new plane[size];
    }

    void set()
    {

        for (int i = 0; i < size; i++)
        {
            ptr[i].setp();
            if (i >= 1)
            {
                for (int j = 0; j < i; j++)
                {
                    while (ptr[i].getm() == ptr[j].getm())
                    {
                        cout << "Такая модель самолёта уже существует, укажите новую модель" << endl;
                        ptr[i].setp();
                    }
                }
            }
        }
    }

    void out()
    {
        cout << "Множество самолётов" << endl;
        for (int i = 0; i < size; i++)
            cout << ptr[i];
    }

    string getm(int &i)
    {
        return ptr[i].getm();
    }

    int getsize()
    {
        return size;
    }
};

class airport
{
    string name;
    plane *ptr;
    int size;

public:
    void set()
    {

        cout << "Введите ICAO аэропорта" << endl;
        cin >> name;
        cout << "Введите кол-во самолётов" << endl;
        cin >> size;

        ptr = new plane[size];

        for (int i = 0; i < size; i++)
        {
            ptr[i].setp();
        }
    }

    void out()
    {
        cout << name << endl;
        for (int i = 0; i < size; i++)
            cout << ptr[i];
    }

    int getsize()
    {
        return size;
    }

    int getpn(int &i)
    {
        return ptr[i].getpn();
    }

    string getm(int &i)
    {
        return ptr[i].getm();
    }

    string getname()
    {
        return name;
    }
};

int main()
{
    cout << "Создадим множество самолётов" << endl;
    mnosh planes;
    airport *air;
    int n;

    planes.set();
    cout << "Введите кол-во аэропорторв" << endl;
    cin >> n;
    try
    {
        if (n > 10)
        {
            throw 0;
        }
    }
    catch (int)
    {
        cout << "Их может быть не больше 10" << endl;
        exit(1);
    }
    air = new airport[n];
    for (int i = 0; i < n; i++)
        air[i].set();

    cout << endl
         << endl;
    planes.out();
    cout << endl;
    for (int i = 0; i < n; i++)
    {
        air[i].out();
        cout << endl;
    }

    int count;
    for (int a = 0; a < n; a++)
    {
        count = 0;

        for (int i = 0; i < planes.getsize(); i++)
        {

            for (int j = 0; j < air[a].getsize(); j++)
            {

                if (planes.getm(i) == air[a].getm(j))
                {
                    count++;
                    // cout << count <<endl;
                    break;
                }
            }
        }
        if (count == planes.getsize())
            cout << "В эропорту " << air[a].getname() << " на эксплуататции все типы самолётов" << endl
                 << endl;
    }

    for (int i = 0; i < planes.getsize(); i++)
    {
        count = 0;
        for (int a = 0; a < n; a++)
        {
            for (int j = 0; j < air[a].getsize(); j++)
            {
                if (planes.getm(i) == air[a].getm(j))
                {
                    count++;
                    break;
                }
            }
        }
        if (count == 0)
        {
            cout << planes.getm(i) << " не эксплуатируется ни в одном из аэропортов" << endl
                 << endl;
        }
    }

    for (int a = 0; a < n; a++)
    {
        count = 0;
        for (int j = 0; j < air[a].getsize(); j++)
        {
            count += air[a].getpn(j);
        }
        cout << "Кол-во пассажиров, перевозимых в " << air[a].getname() << ": " << count << endl;
    }
}
