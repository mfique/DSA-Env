#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

const int INF = 1e9;

int main() {
    int n = 6; // Vertices A-F (0-5)
    vector<pair<int, int>> adj[n];

    adj[0].push_back({1, 3});
    adj[0].push_back({3, 1});
    adj[1].push_back({0, 3});
    adj[1].push_back({2, 1});
    adj[1].push_back({3, 3});
    adj[2].push_back({1, 1});
    adj[2].push_back({3, 1});
    adj[2].push_back({4, 5});
    adj[3].push_back({0, 1});
    adj[3].push_back({1, 3});
    adj[3].push_back({2, 1});
    adj[3].push_back({4, 6});
    adj[4].push_back({2, 5});
    adj[4].push_back({3, 6});
    adj[4].push_back({5, 2});
    adj[5].push_back({4, 2});

    vector<bool> visited(n, false);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({0, 0}); // weight, vertex
    int cost = 0;

    while (!pq.empty()) {
        auto [w, u] = pq.top();
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;
        cost += w;
        for (auto [v, weight] : adj[u]) {
            if (!visited[v])
                pq.push({weight, v});
        }
    }

    cout << "MST cost using Prim: " << cost << endl;
    return 0;
}
