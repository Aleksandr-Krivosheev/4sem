#include <iostream>
#include <list>
#include <string>
using namespace std;

struct vid
{
    string name;
    int math, inf, fiz;
};

istream &operator>>(istream &in, vid &elem)
{
    getline(in, elem.name, ',');
    in.ignore(1);
    in >> elem.math;
    in.ignore(2);
    in >> elem.inf;
    in.ignore(2);
    in >> elem.fiz;
    return in;
}
ostream &operator<<(ostream &out, const vid &elem)
{
    out << "Фамилия:  " << elem.name << "\nОценка по математике: " << elem.math << "\nОценка по информатике:  " << elem.inf << "\nОценка по физике:  " << elem.fiz << endl;
    return out;
}
/*Имеется информация по итогам экзаменов в институте всего в списке N
человек.  По каждому из студентов имеются  следующие сведения : фамилия ,
оценка по математике, оценка по информатике и оценка по x. Ввести
информацию об экзаменах и напечатать количество и фамилии  студентов ,
которые получили на экзамене  две пятерки и одну четверку.*/
int main()
{
    int n;
    cout << "Введите кол-во человек ";
    cin >> n;
    int cons = 0;

    list<vid> l(n);
    cout << "Введите инфу о людях через запятую\n";
    for (auto &el : l)
    {
        cin >> el;
    }
    cout << "Ваша инфа по фильмам:" << endl;
    for (auto &el : l)
    {
        cout << el;
    }
    cout << "Фамилии людей получившие 2 пятерки и 1 четверку:";
    for (auto iter = l.begin(); iter != l.end(); iter++)
    {
        if (iter->inf+ iter->fiz+ iter->math == 14)
        {
            cout << iter->name<< endl;
            cons++;
        }
    }
    if(cons!=0)
    cout << "Кол-во людей получившие 2 пятерки и 1 четверку:" << cons << endl;
    else
    cout << "Нет таких людей"<< endl;

    return 0;
}
