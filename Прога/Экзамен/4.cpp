template <class T>
class matr
{
    T **p;
    int x_size, y_size;

public:
    matr(int size1 = 4, int size2 = 4)
    {
        x_size = size 1;
        y_size = size 2;
        p = new T *[y_size];
        for (int i = 0; i < y_size; i++)
        {
            p[i] = new T[x_size];
        }
    }
    ~matr()
    {
        for (int i = 0; i < y_size; i++)
        {
            delete[] p[i];
        }
        delete[] p;
    }
    int getx_size() { return x_size; }
    int gety_size() { return x_size; }

    T getElem(int i, int j) {return (p[i][j]; }

    void assignElem(int i, int j, T value)
    {
        p[i][j] = value;
    }

    void assign_matr();
    void output_matr();
};

// opisanie metodov shablona
template <class T>
void matr<T>::assign_matr()
{
    T value;
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            cout << "matr[" << i << "][" << j << "] = ";
            cin >> value; //для использования надо перегрузить >>
            this->assignElem(i, j, value);
        }
    }
}
template <class T>
void matr<T>::output_matr()
{
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            cout << getElem(i, j);
        }
    }
}
//специализация шаблона функции вывода matr для типа complex
template <>
void matr<complex>::output_matr()
{
    for (int i = 0; i < y_size; i++)
    {
        for (int j = 0; j < x_size; j++)
        {
            getElem(i, j).output();
        } // вызывается вывод комплексного числа
    }
}
