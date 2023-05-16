#include <iostream>
#include <string.h>
using namespace std;
template <class T, int SIZE>
class Array
{
protected:
    T Elements[SIZE];

public:
    Array()
    {
        for (int i = 0; i < SIZE; i++)
            Elements[i] = i + 10;
    }
    T &operator[](int nIndex)
    {
        return Elements[nIndex];
    }
    T &operator=(const Array &ob)
    {
        for (int i = 0; i < SIZE; i++)
            Elements[i] = ob.Elements[i];
    }
};
template <class T, int SIZE>
class IntArray : public Array<int, SIZE>
{
public:
    void print()
    {
        for (int i = 0; i < SIZE; i++)
            cout << Array<T, SIZE>::Elements[i] << endl;
    }
};

int main()
{
    IntArray<int, 20> Arr;
    Arr[0] = 77;
    Arr[18] = 88;
    cout << "polj=" << endl;
    Arr.print(); //печатает с учетом новых значений
    cout << "konez " << endl;
    return 0;
}