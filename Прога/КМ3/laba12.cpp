#include <iostream>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL));
    int **arr;
    arr = new int *[20];
    for (int i = 0; i < 20; i++)
    {
        arr[i] = new int[12];
    }

    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            arr[i][j] = rand() % 2;
        }
    }

    cout << "матрица:" << endl;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 12; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "первая часть:          вторая часть:" << endl;
    for (int i = 0; i < 20; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            cout << arr[i][j] << " ";
        }

        cout << "           ";
        for (int j = 6; j < 12; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int sum1 = 0;
    int sum2 = 0;
    int min1 = 100;
    int min2 = 100;
    int elem1;
    int elem2;

    for (int j = 0; j < 6; j++)
    {
        sum1 = 0;
        for (int i = 0; i < 20; i++)
        {
            if (arr[i][j] == 1)
            {
                for (int k = 6; k < 12; k++)
                {
                    if (arr[i][k] == 1)
                    {
                        sum1++;
                    }
                }
            }
        }
        cout << sum1 << " ";
        if (sum1 < min1)
        {
            elem1 = j;
            min1 = sum1;
        }
    }
    for (int j = 0; j < 6; j++)
    {
        sum1 = 0;
        for (int i = 0; i < 20; i++)
        {
            if (arr[i][j] == 1)
            {
                for (int k = 6; k < 12; k++)
                {
                    if (arr[i][k] == 1)
                    {
                        sum1++;
                    }
                }
            }
        }
        if (sum1 == min1)
        {
            cout << endl;
            cout << "Элемент из второй половины: " << j + 1 << endl;
        }
    }

    cout << "\nВторая часть" << endl;
    for (int j = 6; j < 12; j++)
    {
        sum2 = 0;
        for (int i = 0; i < 20; i++)
        {
            if (arr[i][j] == 1)
            {
                for (int k = 0; k < 6; k++)
                {
                    if (arr[i][k] == 1)
                    {
                        sum2++;
                    }
                }
            }
        }
        cout << sum2 << " ";
        if (sum2 <= min2)
        {
            elem2 = j;
            min2 = sum2;
        }
    }
    for (int j = 6; j < 12; j++)
    {
        sum2 = 0;
        for (int i = 0; i < 20; i++)
        {
            if (arr[i][j] == 1)
            {
                for (int k = 0; k < 6; k++)
                {
                    if (arr[i][k] == 1)
                    {
                        sum2++;
                    }
                }
            }
        }
        if (sum2 == min2)
        {
            cout << endl;
            cout << "Элемент из второй половины: " << j + 1 << endl;
        }
    }

    //cout << endl;
    //cout << "Элемент из первой половины: " << elem1 + 1 << endl;
    //cout << "Элемент из второй половины: " << elem2 + 1 << endl;
}
