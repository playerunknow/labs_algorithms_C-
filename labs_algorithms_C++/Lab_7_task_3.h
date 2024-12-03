
#include <iostream>
#include "lab_7_task_2.h"

using namespace std;


void lab_7_task_3()
{
    Graph_7_2 g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    auto mst = kruskal(g);

    // Виведення результату
    cout << "Minimum spanning tree:\n";
    int totalWeight = 0;
    for (auto& edge : mst) {
        int weight, u, v;
        tie(weight, u, v) = edge;
        cout << "ridge " << u << "-" << v << " with weight " << weight << "\n";
        totalWeight += weight;
    }
    cout << "Total cost of minimum core tree: " << totalWeight << "\n";
}
