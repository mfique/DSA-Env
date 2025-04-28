#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

vector<int> parent;

int find_set(int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b)
        parent[b] = a;
}

int main() {
    int n = 6; // Vertices A-F (0-5)
    vector<Edge> edges = {
        {0, 1, 4}, {0, 2, 4}, {1, 2, 2}, {1, 3, 5},
        {2, 3, 5}, {2, 4, 11}, {3, 4, 2}, {3, 5, 6}, {4, 5, 7}
    };
    
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    
    sort(edges.begin(), edges.end());

    int cost = 0;
    vector<Edge> result;
    for (Edge e : edges) {
        if (find_set(e.u) != find_set(e.v)) {
            cost += e.weight;
            result.push_back(e);
            union_sets(e.u, e.v);
        }
    }

    cout << "MST Cost: " << cost << endl;
    for (Edge e : result)
        cout << e.u << " - " << e.v << " : " << e.weight << endl;

    return 0;
}

