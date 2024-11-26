#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Graph_2 {
private:
    int num_vertices;
    vector<vector<int>> adj_list;

public:
    // Конструктор для ініціалізації списку суміжності
    Graph_2(int num_vertices) {
        this->num_vertices = num_vertices;
        adj_list.resize(num_vertices);
    }

    // Метод для додавання орієнтованого ребра
    void add_edge(int src, int dest) {
        if (src < num_vertices && dest < num_vertices) {
            adj_list[src].push_back(dest);
        }
    }

    // Метод для видалення орієнтованого ребра
    void remove_edge(int src, int dest) {
        if (src < num_vertices) {
            auto it = find(adj_list[src].begin(), adj_list[src].end(), dest);
            if (it != adj_list[src].end()) {
                adj_list[src].erase(it);
            }
        }
    }

    // Метод для виведення списку суміжності
    void display() const {
        for (int vertex = 0; vertex < num_vertices; ++vertex) {
            cout << "top " << vertex << ": ";
            for (int dest : adj_list[vertex]) {
                cout << dest << " ";
            }
            cout << endl;
        }
    }
};

void lab_6_task_2()
{
    Graph_2 graph(5); // Створюємо граф із 5 вершинами
    graph.add_edge(0, 1); // Додаємо дугу з вершини 0 до вершини 1
    graph.add_edge(1, 2); // Додаємо дугу з вершини 1 до вершини 2
    graph.add_edge(3, 4); // Додаємо дугу з вершини 3 до вершини 4
    graph.display();      // Виводимо списки суміжних вершин
}
