#include <iostream>
#include <conio.h>
#include <windows.h>


#define type complex



using namespace std;

class complex
{
    double real, image;

public:
    complex()
    {
        real = 0;
        image = 0;
    }

    void set(double x, double y)
    {
        real = x;
        image = y;
    }

    double getr()
    {
        return real;
    }

    double geti()
    {
        return image;
    }

    complex& operator+(const complex& x)
    {
        real += x.real;
        image += x.image;
        return *this;
    }

    complex& operator-(const double x)
    {
        real -= x;
        image -= x;
        return *this;
    }

    complex& operator/(const double x)
    {
        real /= x;
        image /= x;
        return *this;
    }

    complex& operator*(const double x)
    {
        real *= x;
        image *= x;
        return *this;
    }

    complex& operator=(const double x)
    {
        real = x;
        image = x;
        return *this;
    }

    bool operator==(const complex& x) {
        return (real == x.real) && (image == x.image);
    }

    bool operator==(const int& x) {
        return (real == x) && (image == x);
    }

    bool operator!=(const int& x) {
        return (real == x) && (image == x);
    }

    bool operator>(const complex& x) { return (real > x.real) && (image > x.image); }

    bool operator>=(const complex& x) { return (real >= x.real) && (image >= x.image); }

    bool operator<(const complex& x) { return (real < x.real) && (image < x.image); }

    bool operator<=(const complex& x) { return (real <= x.real) && (image <= x.image); }

    complex& operator=(const complex& x)
    {
        real = x.real;
        image = x.image;
        return *this;
    }


    friend istream& operator>>(istream& in, complex& x);

    friend ostream& operator<<(ostream& out, const complex& x);
};

istream& operator>>(istream& in, complex& x)
{
    cin >> x.real >> x.image;
    return in;
};

ostream& operator<<(ostream& out, const complex& x)
{
    out << x.real << " + " << x.image << "i";
    return out;
};










template <typename T> class mnosh
{
protected:
    int size;
    T* ptr;
    T timeptr;
public:
    mnosh()
    {
        size = 0;
        ptr = nullptr;
    }

    void set()
    {
        cout << "Введите кол-во элементов множества" << endl;
        cin >> size;
        ptr = new T[size];

        cout << "Введите элементы множества" << endl;
        for (int i = 0; i < size; i++)
        {
            setelem(i);
        }

    }

    void setsize(int& newsize)
    {
        size = newsize;
        ptr = new T[size];
    }



    void setelem(int& i)
    {

    re:
        cin >> ptr[i];
        if (i >= 1)
        {
            for (int j = 0; j < i; j++)
            {
                while (ptr[i] == ptr[j])
                {
                    cout << "Такой элемент множества уже есть, введите новый" << endl;
                    goto re;
                }


            }
        }


    }

    void copy(mnosh& A, mnosh& B)
    {
        for (int i = 0; i < B.getsize(); i++)
            B.ptr[i] = A.ptr[i];
    }


    void setelemM(mnosh& A, mnosh& B, mnosh& C)
    {


        for (int i = 0; i < A.getsize(); i++)
        {
            C.ptr[i] = A.getptr(i);
        }



        int a = 0;
        for (int i = A.getsize(); i < C.getsize(); i++)
        {
            C.ptr[i] = B.getptr(a);
            a++;
        }

    }


    void setelemC(mnosh& A, mnosh& B, mnosh& C, int& a)
    {
        a = 0;
        for (int i = 0; i < A.getsize(); i++)
        {
            for (int j = 0; j < B.getsize(); j++)
            {
                if (A.getptr(i) == B.getptr(j))
                {
                    C.ptr[a] = A.getptr(i);
                    a++;
                }
            }
        }   
        

    }

    void out()
    {
        for (int i = 0; i < size; i++)
            cout << ptr[i] << " ";
        cout << endl;
    }

    T getptr(int& i)
    {
        return ptr[i];
    }

    int getsize()
    {
        return size;
    }



    void push_back()
    {
        cout << "Добавьте новый элемент в множество" << endl;
        int newsize = size + 1;

        T* temp = new T[newsize];
        memcpy(temp, ptr, newsize * sizeof(T));

        delete[] ptr;
        ptr = temp;
        temp = nullptr;

        setelem(size);
        size++;
    }

    void erase(int& a)
    {

        
            int newsize = size - 1;
            T* temp = new T[newsize];
            for (int i = 0; i < a; i++)
            {
                temp[i] = ptr[i];
            }

            for (int i = a; i < newsize; i++)
            {
                temp[i] = ptr[i + 1];
            }


            delete[] ptr;
            ptr = temp;
            temp = nullptr;

            size--;
        
    }



    void check(mnosh& A)
    {
        for (int i = 0; i < A.getsize(); i++)
        {
            timeptr = A.getptr(i);
            for (int j = 0; j < i - 1; j++)
            {
                if (timeptr == A.getptr(j))
                {
                    A.erase(j);
                }
            }
            for (int j = i + 1; j < A.getsize(); j++)
                if (timeptr == A.getptr(j))
                {
                    A.erase(j);
                }

        }

    }


    ~mnosh()
    {
        delete[] ptr;
    }

};




class sol : protected mnosh<type> 
{
    int size;
    mnosh* mn;
public:

    sol()
    {
        size = 0;
        mn = nullptr;
    }

    void set()
    {
        cout << "Введите начальное кол-во множеств" << endl;
        cin >> size;
        mn = new mnosh[size];
        for (int i = 0; i < size; i++)
        {
            mn[i].set();
        }
    }


    void merge()
    {
        if (size < 2) { cout << "Множеств меньше двух" << endl; }
        else
        {
            mnosh temp;
            int mn1, mn2;
            int sizetemp;

            cout << "Выберете номера двух множеств для объединения" << endl;
            cin >> mn1 >> mn2;
            mn1--; mn2--;



            sizetemp = mn[mn1].getsize() + mn[mn2].getsize();

            temp.setsize(sizetemp);
            temp.setelemM(mn[mn1], mn[mn2], temp);

            temp.check(temp);

            temp.out();

        }
    }

    void cros()
    {

        if (size < 2) { cout << "Множеств меньше двух" << endl; }
        else
        {
            mnosh temp,temp2;
            int mn1, mn2;
            int sizetemp, count;

            cout << "Выберете номера двух множеств для пересечения" << endl;
            cin >> mn1 >> mn2;
            mn1--; mn2--;
            sizetemp = mn[mn1].getsize() + mn[mn2].getsize();

            temp.setsize(sizetemp);
            temp.setelemC(mn[mn1], mn[mn2], temp, count);

            temp2.setsize(count);
            

            temp2.copy(temp, temp2);

           
            temp2.out();

        }
    }

    bool include()
    {

           
            int mn1,mn2, a;
            

            cout << "Выберете элемент множества, коорый хотите проверить (введите сначала номер множества затем номер элемента)" << endl;
            cin >> mn1 >> a;
            mn1--; a--;
            cout << "Выберете множество для проверки" << endl;
            cin >> mn2;
            mn2--;
            int b = 0, c = mn[mn2].getsize()-1;
            if ((mn[mn1].getptr(a) >= mn[mn2].getptr(b)) && (mn[mn1].getptr(a) <= mn[mn2].getptr(c))) return true; else return false;
        
    }

    void add()
    {
        int mn1;
        cout << "Выберите множество в которое добавить элемент" << endl;
        cin >> mn1;
        mn1--;

        mn[mn1].push_back();

    }

    void del()
    {
        int mn1, a;
        cout << "Выберите множество из которого хотите удалить элемент" << endl;
        cin >> mn1;
        mn1--;

        cout << "Выберите элемент, который хотите удалить" << endl;
        cin >> a;
        a--;

        if (mn[mn1].getsize() < a)
        {
            cout << "Выход за границы" << endl;
        }
        else mn[mn1].erase(a);

    }


    void out()
    {
        for (int i = 0; i < size; i++)
            mn[i].out();

    }

};




int main()
{
    SetConsoleOutputCP(1251);



    sol A;


    int choice;
    

    while (true)
    {
        cout << endl;
        cout << "1 - Создать множества" << endl;
        cout << "2 - Вывести множества" << endl;
        cout << "3 - Добавить элемент во множество" << endl;
        cout << "4 - Удалить элемент из множества" << endl;
        cout << "5 - Обединение множеств" << endl;
        cout << "6 - Пересечение множеств" << endl;
        cout << "7 - Проверить включение элемента" << endl;
        cout << "0 - Выход" << endl;
        cout << endl << ">> ";

        cin >> choice;

        switch (choice)
        {
        case 1:
            A.set();
            break;
        case 2:
            A.out();
            break;
        case 3:
            A.add();
            break;
        case 4:
            A.del();
            break;
        case 5:
            A.merge();
            break;
        case 6:
            A.cros();
            break;
        case 7:
            if (A.include() == true)
                cout << "Элемент включён" << endl;  else cout << "Элемент не включён" << endl;
            break;
        case 0:
            return 0;
        }
    }






}