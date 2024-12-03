#pragma once

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

using namespace std;

class Graph_7_2
{
public:
    int vertices; // Кількість вершин
    vector<tuple<int, int, int>> edges; // Список ребер (вага, u, v)

    Graph_7_2(int vertices)
    {
        this->vertices = vertices;
    }

    void addEdge(int u, int v, int weight)
    {
        edges.push_back(make_tuple(weight, u, v));
    }

    vector<tuple<int, int, int>> getEdges()
    {
        // Повертає всі ребра, відсортовані за вагою
        sort(edges.begin(), edges.end());
        return edges;
    }
};

class UnionFind
{
private:
    vector<int> parent;
    vector<int> rank;

public:
    UnionFind(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i)
        {
            parent[i] = i;
        }
    }

    int find(int u)
    {
        if (parent[u] != u)
        {
            parent[u] = find(parent[u]); // Стиснення шляху
        }
        return parent[u];
    }

    void unionSets(int u, int v)
    {
        int rootU = find(u);
        int rootV = find(v);

        if (rootU != rootV)
        {
            if (rank[rootU] > rank[rootV])
            {
                parent[rootV] = rootU;
            }
            else if (rank[rootU] < rank[rootV])
            {
                parent[rootU] = rootV;
            }
            else
            {
                parent[rootV] = rootU;
                rank[rootU]++;
            }
        }
    }
};

vector<tuple<int, int, int>> kruskal(Graph_7_2& graph)
{
    vector<tuple<int, int, int>> mst; // Список ребер мінімального остового дерева
    UnionFind uf(graph.vertices);

    // Отримуємо відсортовані за вагою ребра
    auto edges = graph.getEdges();

    for (auto& edge : edges)
    {
        int weight, u, v;
        tie(weight, u, v) = edge;

        // Якщо вершини u і v не в одній компоненті, додаємо ребро до MST
        if (uf.find(u) != uf.find(v))
        {
            uf.unionSets(u, v);
            mst.push_back(edge);
        }
    }

    return mst;
}
