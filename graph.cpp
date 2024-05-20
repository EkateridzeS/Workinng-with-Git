#include <iostream>
#include <vector> 

using namespace std;

int main() {
    setlocale(LC_ALL, "RUS"); // русский язык для отображения в консоли
    int n, m; // n - количество вершин, m - количество рёбер
    cout << "Введите количество вершин и количество рёбер: ";
    cin >> n >> m;

    vector<vector<int>> adj_list(n); // список смежности для хранения смежных вершин

    cout << "Введите номера вершин, соединённых рёбрами (например, для ребра между вершинами 1 и 2 введите '1 2'):\n";
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj_list[u].push_back(v);
        adj_list[v].push_back(u); // для неориентированного графа
    }

    int vertex;
    cout << "Введите номер вершины, для которой хотите узнать количество смежных вершин: ";
    cin >> vertex;

    int num_adjacent_vertices = adj_list[vertex].size();
    cout << "Количество вершин, смежных с вершиной " << vertex << ": " << num_adjacent_vertices << endl;

    return 0;
}