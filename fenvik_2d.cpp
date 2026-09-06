#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
ll m;
const int N = 1e3;
ll arr[N][N];
ll s[N][N];

ll f(ll x) {
    return x & (x+1);
}

ll g(ll x) {
    return x | (x+1);
}

void update(ll x, ll y, ll val) {
    for (int i = x; i < n; i = g(i)) {
        for (int j = y; j < n; j = g(j)) {
            s[i][j] += val;
        }
    }
}

ll pref_sum(ll x, ll y) {
    if (x < 0 || y < 0) {
        return 0;
    }
    ll ans = 0;
    for (int i = x; i >= 0; i = f(i)-1) {
        for (int j = y; j >= 0; j = f(j)-1) {
            ans += s[i][j];
        }
    }
    return ans;
}

ll get_sum(ll l1, ll r1, ll l2, ll r2) {
    return pref_sum(l2, r2) - pref_sum(l2, r1-1) - pref_sum(l1-1, r2) + pref_sum(l1-1, r1-1);
}

void build() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            update(i, j, arr[i][j]);
        }
    }
}

int main () {
    cin >> n >> m;
    string str;
    ll a, b;
    ll l1, r1, l2, r2;
    for (int i = 0; i < m; i++) {
        cin >> str;
        if (str[0] == 'a') {
            cin >> l1 >> r1;
            update(l1-1, r1-1, 1);
        } else {
            cin >> l1 >> r1 >> l2 >> r2;
            cout << get_sum(l1-1, r1-1, l2-1, r2-1) << '\n';
        }
    }
}