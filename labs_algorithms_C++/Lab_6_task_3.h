#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Graph_3 {
private:
    int num_vertices;
    vector<vector<int>> adj_list;

    // Допоміжний метод для обходу в глибину
    void dfs_util(int vertex, vector<bool>& visited) {
        // Позначаємо поточну вершину як відвідану
        visited[vertex] = true;
        cout << vertex << " ";

        // Проходимо всіх сусідів вершини
        for (int neighbor : adj_list[vertex]) {
            if (!visited[neighbor]) {
                dfs_util(neighbor, visited);
            }
        }
    }

public:
    // Конструктор для ініціалізації списку суміжності
    Graph_3(int num_vertices) {
        this->num_vertices = num_vertices;
        adj_list.resize(num_vertices);
    }

    // Метод для додавання орієнтованого ребра
    void add_edge(int src, int dest) {
        if (src < num_vertices && dest < num_vertices) {
            adj_list[src].push_back(dest);
        }
    }

    // Метод для запуску обходу в глибину
    void dfs(int start_vertex) {
        // Ініціалізуємо список для відстеження відвіданих вершин
        vector<bool> visited(num_vertices, false);
        // Запускаємо DFS з початкової вершини
        dfs_util(start_vertex, visited);
    }
};

void lab_6_task_3()
{
    Graph_3 graph(5); // Створюємо граф із 5 вершинами
    graph.add_edge(0, 1); // Додаємо дугу з вершини 0 до вершини 1
    graph.add_edge(0, 2); // Додаємо дугу з вершини 0 до вершини 2
    graph.add_edge(1, 3); // Додаємо дугу з вершини 1 до вершини 3
    graph.add_edge(1, 4); // Додаємо дугу з вершини 1 до вершини 4
    graph.add_edge(3, 4); // Додаємо дугу з вершини 3 до вершини 4

    // Викликаємо обхід у глибину, починаючи з вершини 0
    cout << "Depth-first traversal of the graph starting from vertex 0:" << endl;
    graph.dfs(0);
}
