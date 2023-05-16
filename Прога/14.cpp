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
        std::cout << "Ошибка открытия файла для чтения" << endl;
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
    std::cout << "Схема:" << endl;
    for (int i = 0; i < num_chains; i++)
    {
        for (int j = 0; j < num_elem; j++)
        {
            std::cout << mas[i][j] << " ";
        }
        std::cout << endl;
    }
}

//вывод частей
void output_part(int part1[num_chains][n], int part2[num_chains][n], int part3[num_chains][n])
{
    std::cout << " Part1   |  Part2   |  Part3  " << endl;
    for (int i = 0; i < num_chains; i++)
    {
        for (int j = 0; j < n; j++)
        {
            std::cout << part1[i][j] << " ";
        }
        std::cout << " | ";
        for (int j = 0; j < n; j++)
        {
            std::cout << part2[i][j] << " ";
        }
        std::cout << " | ";
        for (int j = 0; j < n; j++)
        {
            std::cout << part3[i][j] << " ";
        }
        std::cout << endl;
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

//заполнение частей
void max_in(int part[num_chains][n], int mas[num_chains][num_elem], int k, string &s)
{
    int max[num_elem];
    int max_elem = 0, max_number = 0;
    vector<int> ch(num_chains);
    vector<int>::iterator it;
    ch = chain(part);
    for (int i = 0; i < num_elem; i++)
    {
        max[i] = 0;
        for (int j = 0; j < num_chains; j++)
        {
            if ((mas[j][i] == ch[j]) && (mas[j][i] == 1))
                max[i] += 1;
        }
    }
    for (int i = 0; i < num_elem; i++)
    {
        if (max[i] > max_elem)
        {
            max_number = i;
            max_elem = max[i];
        }
    }
    s += " " + std::to_string(max_number + 1);

    for (int i = 0; i < num_chains; i++)
    {
        part[i][k] = mas[i][max_number];
        mas[i][max_number] = 0;
    }
}

//задействованное число контактов разъема
void counter(int part1[num_chains][n], int part2[num_chains][n], int part3[num_chains][n])
{
    vector<int> ch1(num_chains);
    vector<int> ch2(num_chains);
    vector<int> ch3(num_chains);
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    ch1 = chain(part1);
    ch2 = chain(part2);
    ch3 = chain(part3);
    for (int i = 0; i < num_chains; i++)
    {
        if ((ch1[i] == ch2[i]) && (ch1[i] == 1))
            count1++;
        if ((ch2[i] == ch3[i]) && (ch2[i] == 1))
            count2++;
        if ((ch1[i] == ch3[i]) && (ch1[i] == 1))
            count3++;
    }
    std::cout << "Число связей, соединяющих 1 и 2 платы = " << count1 << endl;
    std::cout << "Число связей, соединяющих 2 и 3 платы = " << count2 << endl;
    std::cout << "Число связей, соединяющих 1 и 3 платы = " << count3 << endl;
};

int main(void)
{
    int mas[num_chains][num_elem]; //схема
    int part1[num_chains][n];      //плата 1
    int part2[num_chains][n];      //плата 2
    int part3[num_chains][n];      //плата 3
    string s1 = "1";
    string s2 = "2";
    string s3 = "3";
    input(mas);
    output(mas);
    first_elem(part1, part2, part3, mas);
    for (int i = 1; i < n; i++)
    {
        max_in(part1, mas, i, s1);
    }
    for (int i = 1; i < n; i++)
    {
        max_in(part2, mas, i, s2);
    }
    for (int i = 1; i < n; i++)
    {
        max_in(part3, mas, i, s3);
    }
    output_part(part1, part2, part3);
    std::cout << "Номера элементов, попавших на плату 1 = " << s1 << endl;
    std::cout << "Номера элементов, попавших на плату 2 = " << s2 << endl;
    std::cout << "Номера элементов, попавших на плату 3 = " << s3 << endl;
    counter(part1, part2, part3);

    return 0;
}
