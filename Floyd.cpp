#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll INF = 1e9;
const int N = 50;
int n;
vector<vector<ll>> dist(N+1, vector<ll>(N+1, INF));

int main () {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <=n; j++) {
            cin >> dist[i][j];
        }
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    
}