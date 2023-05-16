#include <iostream>
#include <list>
using namespace std;

int main(void)
{
        list<double> mas, mas2;
        list<double>::iterator it;
        int A = 0, B = 0, n = 0, el = 0, sum = 0;
        double x;
        cout << "Введите размер массива: " << endl;
        cin >> n;

        cout << "Введите массив чисел: " << endl;
        for (int i = 0; i < n; i++)
        {
                cin >> el;
                mas.push_back(el);
        }

        cout << "Введите диапазон чисел : " << endl;
        cin >> A >> B;

/*         for (int i = mas.size()/2; i != mas.size() ; i++)
        {
                if ((A < mas[i]) && (*it < B))
                {
                        *it = B;
                        sum = sum+1;  
                }
        } */
         it = mas.begin();
        for(int i = 0; i<mas.size()/2;++i)
        {
                it++;
        }
        for (it = it; it != mas.end(); it++)
        {
                if ((A <*it) && (*it < B))
                {
                        *it= B;
                        sum = sum+1;  
                }
        }
 
        for (it = mas.begin(); it != mas.end(); it++)
        {
                mas2.push_front(*it);
        }

        for (it = mas2.begin(); it != mas2.end(); it++)
        {
                cout<< *it <<' ';
        }
        cout << "\n";        
        cout << "кол-во попавши в интервал А В " << sum << endl; 

        return 0;
}