#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int num_vertices;
    vector<vector<int>> adj_matrix;

public:
    // Конструктор для ініціалізації графа
    Graph(int num_vertices) {
        this->num_vertices = num_vertices;
        adj_matrix = vector<vector<int>>(num_vertices, vector<int>(num_vertices, 0));
    }

    // Додаємо орієнтоване ребро
    void add_edge(int src, int dest) {
        if (src < num_vertices && dest < num_vertices) {
            adj_matrix[src][dest] = 1;
        }
    }

    // Видаляємо орієнтоване ребро
    void remove_edge(int src, int dest) {
        if (src < num_vertices && dest < num_vertices) {
            adj_matrix[src][dest] = 0;
        }
    }

    // Виведення матриці суміжності
    void display() {
        for (const auto& row : adj_matrix) {
            for (const auto& val : row) {
                cout << val << " ";
            }
            cout << endl;
        }
    }
};

void lab_6_task_1() 
{
    Graph graph(5);  // Створюємо граф із 5 вершинами
    graph.add_edge(0, 1);  // Додаємо дугу з вершини 0 до вершини 1
    graph.add_edge(1, 2);  // Додаємо дугу з вершини 1 до вершини 2
    graph.add_edge(3, 4);  // Додаємо дугу з вершини 3 до вершини 4
    graph.display();       // Виводимо матрицю суміжності


}
