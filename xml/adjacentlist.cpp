#include <iostream>
#include <vector>
using namespace std;
class Graph {
private:
    vector<pair<int, int> > *adjList;
    int numVertices;
public:
    Graph(int vertices) {
        numVertices = vertices;
        adjList = new vector<pair<int, int> >[numVertices];
    }
    void addEdge(int u, int v, int weight) {
        adjList[u].push_back({v, weight});
        adjList[v].push_back({u, weight}); // For undirected graph
    }
    void printGraph() {
        cout << "Adjacency List:\n";
        for (int i = 0; i < numVertices; i++) {
            cout << i << " -> ";
            for (auto edge : adjList[i]) {
                cout << "(" << edge.first << ", " << edge.second << ") ";
            }
            cout << endl;
        }
    }
    ~Graph() {
        delete[] adjList;
    }
};
int main() {
    int vertices = 5;
    Graph g(vertices);
    g.addEdge(0, 1, 10);
    g.addEdge(0, 2, 5);
    g.addEdge(1, 3, 8);
    g.addEdge(2, 3, 12);
    g.addEdge(3, 4, 6);
    g.printGraph();
    return 0;
}
