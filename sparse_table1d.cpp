#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e5+1;
const ll r = 17;
int n;
int m;
ll arr[N];
ll sparse[r][N];
ll deg[N];

void build() {
    deg[1] = 0;
    for (int i = 2; i <= n; i++) {
        deg[i] = deg[i-1];
        if (!(i & (i-1))) {
            ++deg[i];
        }
    }
    for (int i = 0; i < n; i++) {
        sparse[0][i] = arr[i];
    }
    for (int k = 0; k < r-1; k++) {
        for (int i = 0; i < n; i++) {
            sparse[k + 1][i] = sparse[k][i];
            ll j = i + (1 << (k));
            if (j < n) {
                sparse[k + 1][i] = min(sparse[k][i], sparse[k][j]);
            }
        }
    }
}


int get_min(int l, int r) {
    ll k = deg[r-l+1];
    return min(sparse[k][l], sparse[k][r - (1 << k)+1]);
}


int main () {
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build();
    cin >> m;
    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        cout << get_min(l-1, r-1) << "\n";
    }
}