#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Graph {
public:
    int vertices; // Кількість вершин
    vector<tuple<int, int, int>> edges; // Список ребер (вага, u, v)

    Graph(int vertices) {
        this->vertices = vertices;
    }

    void addEdge(int u, int v, int weight) {
        edges.push_back(make_tuple(weight, u, v));
    }

    vector<tuple<int, int, int>> getEdges() {
        // Повертає всі ребра, відсортовані за вагою
        sort(edges.begin(), edges.end());
        return edges;
    }
};

class UnionFind {
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (parent[u] != u) {
            parent[u] = find(parent[u]); // Стиснення шляху
        }
        return parent[u];
    }

    void unionSets(int u, int v) {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV) {
            if (rank[rootU] > rank[rootV]) {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV]) {
                parent[rootU] = rootV;
            }
            else {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<tuple<int, int, int>> kruskal(Graph& graph) {
    vector<tuple<int, int, int>> mst; // Список ребер мінімального остового дерева
    UnionFind uf(graph.vertices);

    // Отримуємо відсортовані за вагою ребра
    auto edges = graph.getEdges();

    for (auto& edge : edges) {
        int weight, u, v;
        tie(weight, u, v) = edge;

        // Якщо вершини u і v не в одній компоненті, додаємо ребро до MST
        if (uf.find(u) != uf.find(v)) {
            uf.unionSets(u, v);
            mst.push_back(edge);
        }
    }

    return mst;
}

int main() {
    Graph g(4);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 6);
    g.addEdge(0, 3, 5);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 4);

    auto mst = kruskal(g);

    // Виведення результату
    cout << "Мінімальне остове дерево:\n";
    int totalWeight = 0;
    for (auto& edge : mst) {
        int weight, u, v;
        tie(weight, u, v) = edge;
        cout << "Ребро " << u << "-" << v << " з вагою " << weight << "\n";
        totalWeight += weight;
    }
    cout << "Загальна вартість мінімального остового дерева: " << totalWeight << "\n";

    return 0;
}
