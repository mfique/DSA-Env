#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1e9;

int main() {
    int n = 6; // Vertices A-F (0-5)
    vector<pair<int, int>> adj[n];

    adj[0].push_back({1, 2});
    adj[0].push_back({2, 5});
    adj[1].push_back({0, 2});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 2});
    adj[2].push_back({0, 5});
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 3});
    adj[2].push_back({4, 8});
    adj[3].push_back({1, 2});
    adj[3].push_back({2, 3});
    adj[3].push_back({4, 1});
    adj[4].push_back({2, 8});
    adj[4].push_back({3, 1});
    adj[4].push_back({5, 2});
    adj[5].push_back({4, 2});

    int source = 0;
    vector<int> dist(n, INF);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();

        if (d > dist[u]) continue;

        for (auto [v, weight] : adj[u]) {
            if (dist[v] > dist[u] + weight) {
                dist[v] = dist[u] + weight;
                pq.push({dist[v], v});
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Distance from A to " << char('A' + i) << ": " << dist[i] << endl;
    }

    return 0;
}

