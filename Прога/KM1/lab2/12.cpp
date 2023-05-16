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