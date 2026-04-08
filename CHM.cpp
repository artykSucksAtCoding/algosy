#include <bits/stdc++.h>


using namespace std;
const int N = 1e5;

int sz[N];
int parent[N];

// подвязывание каждой за каждую
void make_set(int n) {
    for (int i = 0; i < n; i++) {
        parent[i] = i;
        sz[i] = 1;
    }
}


int get_set(int v) {
    if (v == parent[v]) return v;
    return parent[v] = get_set(parent[v]); }


void union_sets(int v, int u) {
    int a = get_set(v);
    int b = get_set(u);
    if (a != b) {
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a]+=sz[b];
    }
}


int main () {
    int u, v;
    int m;
    int n;
    string s;
    cin >> n >> m;
    vector<string> ans;
    make_set(n);
    for (int i = 0; i < m; i++) {
        cin >> s >> u >> v;
        --u;
        --v;
        if (s == "get") {
            int a = get_set(u);
            int b = get_set(v);
            if (a == b) {
                ans.push_back("YES");
            } else {
                ans.push_back("NO");
            }
            
        } else {
            union_sets(u, v);
        }
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}