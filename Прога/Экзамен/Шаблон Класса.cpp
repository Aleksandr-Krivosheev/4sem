#include <iostream>
#include <stdlib.h>
using namespace std;

// onucaHue wa6noxa Knacca
template <class T, class T1>
class array
{
    T *data;
    int size;
    int index;

public:
    array(int size);
    T1 sum(void);
    T average_value(void);
    void show_array(void);
    int add_value(T);
};

//описание конструктора шаблона класса вне класса
template <class T, class T1>
array<T, T1>::array(int size)
{
    data = new T[size];
    if (data == NULL)
    {
        cerr << "Недостаточно памяти - программа завершается" << endl;
        exit(1);
    }
    array::size = size;
    array::index = 0;
}
//функция вычисления суммы
template <class T, class T1>
T1 array<T, T1>::sum(void)
{
    T1 sum = 0;
    for (int i = 0; i < index; i++)
        sum += data[i];
    return (sum);
}

//вычисление среднего
template <class T, class T1>
T array<T, T1>::average_value(void)
{
    T1 sum = 0;
    for (int i = 0; i < index; i++)
        sum += data[i];
    return (sum / index);
}
//вывод массива
template <class T, class T1>
void array<T, T1>::show_array(void)
{
    for (int i = 0; i < index; i++)
        cout << data[i] << ' ';
    cout << endl;
}

//добавление элемента в массив
template <class T, class T1>
int array<T, T1>::add_value(T Value)
{
    if (index == size)
        return (-1); // Массив полон
    else
    {
        data[index] = Value;
        index++;
        return (0); //Успешно
    }
}

int main(void)
{
    // Массив из 100 элементов целого типа
    array<int, long> numbers(100);
    //Массив из 200 элементов вещественного типа
    array<float, float> values(200);
    int i;
    for (i = 0; i < 50; i++)
        numbers.add_value(i);
    numbers.show_array();
    std::cout << "Сумма чисел равна " << numbers.sum() << std::endl;
    std::cout << "Среднее значение равно " << numbers.average_value() << std::endl;
    for (i = 0; i < 100; i++)
        values.add_value(i * 100);
    values.show_array();
    std::cout << "Сумма чисел равна." << values.sum() << std::endl;
    std::cout << "Среднее значение равно " << values.average_value() << std::endl;
}