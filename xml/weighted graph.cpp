#include <iostream>
#include <vector>
using namespace std;

#define INF 99999  // Representing no connection between nodes

class Graph {
    int V;  // Number of vertices
    vector<vector<int> > adjMatrix;

public:
    Graph(int vertices) {
        V = vertices;
        adjMatrix.resize(V, vector<int>(V, INF));  // Initialize matrix with INF
        for (int i = 0; i < V; i++)
            adjMatrix[i][i] = 0;  // Distance to itself is zero
    }

    void addEdge(int u, int v, int weight) {
        adjMatrix[u][v] = weight;
        adjMatrix[v][u] = weight;  // For undirected graph, remove this line if directed
    }

    void printGraph() {
        cout << "Adjacency Matrix:\n";
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (adjMatrix[i][j] == INF)
                    cout << "INF ";
                else
                    cout << adjMatrix[i][j] << "   ";
            }
            cout << endl;
        }
    }
};

int main() {
    int V = 5;
    Graph g(V);

    g.addEdge(0, 1, 2);
    g.addEdge(0, 4, 7);
    g.addEdge(1, 2, 3);
    g.addEdge(1, 3, 8);
    g.addEdge(1, 4, 5);
    g.addEdge(2, 3, 1);
    g.addEdge(3, 4, 4);

    g.printGraph();

    return 0;
}

