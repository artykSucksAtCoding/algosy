#include <bits/stdc++.h>

typedef long long ll;
using namespace std;


const int N = 100;
const int inf = 1e9;

int main () {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    vector<vector <pair<int, int>>> adj(N+1);
    vector<int>price(N+1);

    vector<int> dist(N+1, inf);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> price[i+1];
    }
    int m;
    int from;
    int to;
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> from >> to;
        adj[from].push_back({price[from], to});
        adj[to].push_back({price[to], from});
    }
    int start = 1;
    dist[1] = 0;
    pq.push({dist[1], 1});
    while (!pq.empty()) {
        int d = pq.top().first;
        int u = pq.top().second;
        pq.pop();
        if (d > dist[u]) continue;
        for (auto& edge: adj[u]) {
            int v =edge.second;
            int w = edge.first;
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u]+w;
                pq.push({dist[u], v});
            }
        }
    }
    if (dist[n] == inf) {
        cout << -1;
    } else {
        cout << dist[n];
    }
    return 0;
}