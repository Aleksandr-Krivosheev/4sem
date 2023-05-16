#include <iostream>
#include <list>
#include <algorithm>

int main()
{
    std::list<int> li;
    for (int nCount = 0; nCount < 5; ++nCount)
        li.push_back(nCount);
    std::list<int>::iterator it;                // объявляем итератор
    it = find(li.begin(), li.end(), 2);         // ищем в списке число 2
    li.insert(it, 7);                           // используем алгоритм list::insert() для добавления числа 7 перед числом 2
    for (it = li.begin(); it != li.end(); ++it) // выводим с помощью цикла и итератора элементы списка
        std::cout << *it << ' ';
    std::cout << '\n';
}
