#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

const int num_elem = 12;           //число элементов
const int num_chains = 20;         //число цепей
const int num_part = 3;            //количество плат
const int n = num_elem / num_part; // максимально возможное число элементов на плате

//заполнение схемы из файла
void input(int mas[num_chains][num_elem])
{
    ifstream i_file;
    i_file.open("test.txt");
    if (!i_file)
    {
        cout << "Ошибка открытия файла для чтения" << endl;
        exit(1);
    }
    for (int i = 0; i < num_chains; i++)
    {
        for (int j = 0; j < num_elem; j++)
        {
            i_file >> mas[i][j];
        }
    }
    i_file.close();
}

//вывод схемы
void output(int mas[num_chains][num_elem])
{
    cout << "Схема:" << endl;
    for (int i = 0; i < num_chains; i++)
    {
        for (int j = 0; j < num_elem; j++)
        {
            cout << mas[i][j] << " ";
        }
        cout << endl;
    }
}

//вывод частей
void output_part(int part1[num_chains][n], int part2[num_chains][n], int part3[num_chains][n])
{
    cout << " Part1   |  Part2   |  Part3  " << endl;
    for (int i = 0; i < num_chains; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << part1[i][j] << " ";
        }
        cout << " | ";
        for (int j = 0; j < n; j++)
        {
            cout << part2[i][j] << " ";
        }
        cout << " | ";
        for (int j = 0; j < n; j++)
        {
            cout << part3[i][j] << " ";
        }
        cout << endl;
    }
}
//заполнение первого элемента плат (1 плата - первый элемент, 2 - второй, 3 - третий)
void first_elem(int part1[num_chains][n], int part2[num_chains][n], int part3[num_chains][n], int mas[num_chains][num_elem])
{
    for (int i = 0; i < num_chains; i++)
    {
        for (int j = 0; j < n; j++)
        {
            part1[i][j] = 0;
            part2[i][j] = 0;
            part3[i][j] = 0;
        }
    }
    for (int i = 0; i < num_chains; i++)
    {
        int j = 0;
        part1[i][j] = mas[i][j];
        part2[i][j] = mas[i][j + 1];
        part3[i][j] = mas[i][j + 2];
        mas[i][j] = mas[i][j + 1] = mas[i][j + 2] = 0;
    }
}

//заполнение только тех цепей, которые входят в данную часть
std::vector<int> chain(int part[num_chains][n])
{
    vector<int> chains(num_chains);
    vector<int>::iterator it;
    for (it = chains.begin(); it != chains.end(); it++)
    {
        *it = 0;
    }
    int count = 0;
    for (int i = 0; i < num_chains; i++)
    {
        count = 0;
        for (int j = 0; j < n; j++)
        {
            count += part[i][j];
        }
        if (count != 0)
            chains[i] = 1;
        else
            chains[i] = 0;
    }
    return chains;
}