#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Структура для хранения ребра
struct Edge {
    int u, v, weight;
    // Оператор сравнения для сортировки по весу
    bool operator<(const Edge& other) const {
        return weight < other.weight;
    }
};

// Функция поиска корня с оптимизацией сжатия путей
int find_set(int v, vector<int>& parent) {
    if (v == parent[v]) return v;
    return parent[v] = find_set(parent[v], parent); // Сжимаем путь
}

// Функция объединения множеств по рангу
void union_sets(int a, int b, vector<int>& parent, vector<int>& rank) {
    a = find_set(a, parent);
    b = find_set(b, parent);
    if (a != b) {
        // Присоединяем дерево с меньшим рангом к большему
        if (rank[a] < rank[b]) swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
    }
}

// Основная функция алгоритма Крускала
long long kruskal(int n, vector<Edge>& edges) {
    // parent[i] - родитель вершины i
    // rank[i] - глубина дерева (для оптимизации)
    vector<int> parent(n);
    vector<int> rank(n, 0);
    
    // Инициализация: каждая вершина — сама себе родитель
    for (int i = 0; i < n; ++i) parent[i] = i;

    // 1. Сортируем ребра по возрастанию веса
    sort(edges.begin(), edges.end());

    long long mst_weight = 0;
    int edges_count = 0;

    // 2. Идем по отсортированным ребрам
    for (const auto& edge : edges) {
        // Если вершины принадлежат разным множествам — объединяем
        if (find_set(edge.u, parent) != find_set(edge.v, parent)) {
            mst_weight += edge.weight;
            union_sets(edge.u, edge.v, parent, rank);
            edges_count++;
        }
    }
    
    return mst_weight;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v >> edges[i].weight;
        edges[i].u--; 
        edges[i].v--;
    }

    // Запуск алгоритма
    cout << kruskal(n, edges) << endl;

    return 0;
}