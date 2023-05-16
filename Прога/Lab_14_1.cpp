#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

class multigraph
{
	int nodes;
	vector<vector<int>> graph;

public:
	multigraph() { nodes = 0; }

	void set_nodes()
	{
		cout << "Введите количество вершин: ";
		cin >> nodes;
	}

	void set_manually()
	{
		set_nodes();

		for (int i = 0; i < nodes; i++)
		{
			vector<int> node;

			for (int j = 0; j < nodes; j++)
			{
				int value;

				cin >> value;
				node.push_back(value);
			}

			graph.push_back(node);
		}
	}

	void set_from_file()
	{
		string filename;

		cout << "Введите имя файла: ";
		cin >> filename;

		fstream file(filename);

		file >> nodes;

		for (int i = 0; i < nodes; i++)
		{
			vector<int> node;

			for (int j = 0; j < nodes; j++)
			{
				int value;

				file >> value;
				node.push_back(value);
			}

			graph.push_back(node);
		}

		this->nodes = nodes;
	}

	void set_random()
	{
		set_nodes();

		int min = 0;
		int max = 2;

		for (int i = 0; i < nodes; i++)
		{
			vector<int> node;

			for (int j = 0; j < nodes; j++)
			{
				if (j < i)
					node.push_back(graph[j][i]);
				else if (j == i)
					node.push_back(0);
				else
					node.push_back(min + (rand() % static_cast<int>(max - min + 1)));
			}

			graph.push_back(node);
		}
	}

	friend ostream &operator<<(ostream &out, multigraph g);

	friend void task(multigraph g);
};

ostream &operator<<(ostream &out, multigraph g)
{
	for (int i = 0; i < g.nodes; i++)
	{
		for (int j = 0; j < g.nodes; j++)
		{
			if (j != g.nodes - 1)
				out << g.graph[i][j] << "  ";
			else
				out << g.graph[i][j] << endl;
		}
	}

	return out;
}

void task(multigraph g)
{
	vector<vector<int>> circuits;
	vector<int> available_nodes;

	for (int i = 0; i < g.nodes; i++)
		available_nodes.push_back(i + 1);

	int M;
	int max_connections = 25;

	cout << endl;
	cout << "Введите количество плат: ";
	cin >> M;
	cout << endl;

	// Пользовательский ввод начальной вершины на каждую плату
	for (int i = 0; i < M; i++)
	{
		vector<int> circuit;
		int node;

		cout << "Доступные вершины: ";
		for (auto node = available_nodes.begin(); node != available_nodes.end(); node++)
		{
			if (node != available_nodes.end() - 1)
				cout << *node << " ";
			else
				cout << *node << endl;
		}

		cout << "Введите вершину для назначения в плату #" << i + 1 << ": ";
		cin >> node;
		circuit.push_back(node);
		available_nodes.erase(remove(available_nodes.begin(), available_nodes.end(), node), available_nodes.end());

		circuits.push_back(circuit);
	}

	auto circuit = circuits.begin();

	while (available_nodes.size() != 0)
	{
		// Начальные значения для поиска
		int node = available_nodes[0];
		int min_available = 0;
		int max_appointed = 0;

		cout << endl;
		cout << circuit - circuits.begin() + 1 << endl;

		// Подсчет количества связей с неназначенными вершинами для первой свободной вершины (задание минимального значения)
		for (int j = 0; j < g.nodes; j++)
		{
			if (find(available_nodes.begin(), available_nodes.end(), j + 1) != available_nodes.end())
				min_available += g.graph[available_nodes[0] - 1][j];
		}

		// Вывод количества связей для первой вершины
		cout << node << " " << min_available << endl;

		// Подсчет количества связей с неназначенными вершинами для каждой свободной вершины (начиная со второй по счету)
		for (int i = 1; i < available_nodes.size(); i++)
		{
			int available = 0;

			for (int j = 0; j < g.nodes; j++)
			{
				if (find(available_nodes.begin(), available_nodes.end(), j + 1) != available_nodes.end())
					available += g.graph[available_nodes[i] - 1][j];
			}

			// Поиск минимума
			if (available < min_available)
			{
				node = available_nodes[i];
				min_available = available;
			}

			// Вывод количества связей для текущей вершины
			cout << available_nodes[i] << " " << available << endl;
		}

		// Вывод найденной вершины, которая имеет минимальное коллличество связей с еще не назначенными
		cout << node << " " << min_available << endl;

		// Добавление найденной вершины в текущую плату
		(*circuit).push_back(node);
		available_nodes.erase(remove(available_nodes.begin(), available_nodes.end(), node), available_nodes.end());

		// Проверка выполнения условия, на использованное количество разъемов платы
		for (auto circuit_check = circuits.begin(); circuit_check != circuits.end(); circuit_check++)
		{
			// Начальное значение для подсчета контактов для текущей платы
			int current_connections = 0;

			// Подсчет количества контактов для текущей вершины с вершинами, которые уже используются в других платах
			for (auto node_check = (*circuit_check).begin(); node_check != (*circuit_check).end(); node_check++)
			{
				for (int j = 0; j < g.nodes; j++)
					if (find(available_nodes.begin(), available_nodes.end(), j + 1) == available_nodes.end() && find((*circuit_check).begin(), (*circuit_check).end(), j + 1) == (*circuit_check).end())
						current_connections += g.graph[*node_check - 1][j];
			}

			// Проверка выполнения условия и конец алгоритма в случае невыполения
			if (current_connections > max_connections)
			{
				cout << endl;
				cout << "Для платы #" << circuit_check - circuits.begin() + 1 << " превышено число контактов разъема ( " << current_connections << " / " << max_connections << " )" << endl;
				cout << "Узлы платы: ";
				for (auto node = (*circuit_check).begin(); node != (*circuit_check).end(); node++)
				{
					if (node != (*circuit_check).end() - 1)
						cout << *node << " ";
					else
						cout << *node;
				}
				cout << endl;
				return;
			}
		}

		//Переход на следующую плату (на первую, если текущая плата последняя)
		circuit++;
		if (circuit == circuits.end())
			circuit = circuits.begin();
	}

	cout << endl;

	//Вывод плат, их вершин и использованное количество связей с другими платами
	for (auto circuit = circuits.begin(); circuit != circuits.end(); circuit++)
	{
		int current_connections = 0;

		cout << "Плата #" << circuit - circuits.begin() + 1 << ": ";

		for (auto node = (*circuit).begin(); node != (*circuit).end(); node++)
		{
			if (node != (*circuit).end() - 1)
				cout << *node << " ";
			else
				cout << *node;

			for (int j = 0; j < g.nodes; j++)
				if (find((*circuit).begin(), (*circuit).end(), j + 1) == (*circuit).end())
					current_connections += g.graph[*node - 1][j];
		}

		cout << "( " << current_connections << " / " << max_connections << " )" << endl;
	}
}

int main(void)
{

	multigraph g;

	int choice;

	cout << endl;
	cout << "1 - Ввести вручную" << endl;
	cout << "2 - Ввести из файла" << endl;
	cout << "3 - Сгенерировать" << endl;

	cout << endl
		 << ">> ";
	cin >> choice;
	cout << endl;

	switch (choice)
	{
	case 1:
		g.set_manually();
		break;

	case 2:
		g.set_from_file();
		break;

	case 3:
		g.set_random();
		break;

	default:
		return 1;
	}

	cout << endl;
	cout << "Матрица смежности мультиграфа:" << endl
		 << endl
		 << g;

	task(g);

	cout << endl;

	return 0;
}