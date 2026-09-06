#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n;
ll m;
const int N = 1e5;
ll arr[N];
ll s[N];

ll f(ll x) {
    return x & (x+1);
}

ll g(ll x) {
    return x | (x+1);
}

void update(ll pos, ll val) {
    for (int i = pos; i < n; i = g(i)) {
        s[i] += val;
    }
}

ll pref_sum(int pos) {
    if (pos < 0) {
        return 0;
    }
    ll ans = 0;
    for (int i = pos; i >= 0; i = f(i)-1) {
        ans += s[i];
    }
    return ans;
}

ll get_sum(int x, int y) {
    return pref_sum(y) - pref_sum(x-1);
}

void build() {
    for (int i = 0; i < n; i++) {
        update(i, arr[i]);
    }
}

int main () {
    cin >> n >> m;
    string str;
    ll a, b;
    for (int i = 0; i < m; i++) {
        cin >> str >> a >> b;
        if (str[0] == 'a') {
            update(a-1, b);
        } else {
            cout << get_sum(a-1, b-1) << '\n';
        }
    }
}