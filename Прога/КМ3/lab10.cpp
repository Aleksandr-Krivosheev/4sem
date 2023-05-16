#include <iostream>
#include <list>
#include <string>
#include <algorithm>
using namespace std;

struct vid
{
    string name;
    int math, inf, fiz;
    void operator()(vid a)
    {
        if (a.math + a.fiz + a.inf == 14)
        {
            cout << a.name<< endl;
        }
        else return false;
    }
};
    void name1(vid a)
    {
        cout<< a.name;
    }
    bool proverka(vid a)
    {
        if (a.math + a.fiz + a.inf == 14)
        {
            cout << a.name<< endl;
            return true;
        }
        else return false;
    }
/* istream &operator>>(istream &in, vid &elem)
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
} */

void show(vid &elem)
{
    cout << "Фамилия:  " << elem.name << "\nОценка по математике: " << elem.math << "\nОценка по информатике:  " << elem.inf << "\nОценка по физике:  " << elem.fiz << endl;
}

void vvod(vid &elem)
{
    getline(cin ,elem.name, ',');
    cin.ignore(1);
    cin >> elem.math;
    cin.ignore(2);
    cin >> elem.inf;
    cin.ignore(2);
    cin >> elem.fiz; 
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
    for_each(l.begin(),l.end(),vvod);
    cout << "Ваша инфа по фильмам:" << endl;
    for_each(l.begin(),l.end(),show);
    cout << "Фамилии людей получившие 2 пятерки и 1 четверку:";
    if(for_each(l.begin(),l.end(),proverka))
    {
            cons++;
    }
    if(cons!=0)
    cout << "Кол-во людей получившие 2 пятерки и 1 четверку:" << cons << endl;
    else
    cout << "\nНет таких людей"<< endl;

    return 0;
}
