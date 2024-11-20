#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices; // Кількість вершин
    vector<vector<int>> adj_matrix; // Матриця суміжності

public:
    // Конструктор
    Graph(int vertices) {
        this->vertices = vertices;
        adj_matrix = vector<vector<int>>(vertices, vector<int>(vertices, 0));
    }

    // Додавання ребра між вершинами u та v
    void add_edge(int u, int v) {
        adj_matrix[u][v] = 1;
        adj_matrix[v][u] = 1; // Неорієнтований граф
    }

    // Виведення матриці суміжності
    void display() {
        for (const auto& row : adj_matrix) {
            for (int val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    Graph graph(5); // Створюємо граф з 5 вершинами
    graph.add_edge(0, 1);
    graph.add_edge(0, 4);
    graph.add_edge(1, 2);
    graph.add_edge(1, 3);
    graph.add_edge(1, 4);
    graph.add_edge(3, 4);

    graph.display(); // Виводимо матрицю суміжності
    return 0;
}
