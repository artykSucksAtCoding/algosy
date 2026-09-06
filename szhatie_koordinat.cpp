#include <bits/stdc++.h>
typedef long long ll;
using namespace std;


int main() {

    std::vector<int> a = {1000000000, 42, 1000000000, -500, 42};
    int n = a.size();
    std::set<int> unique_sorted_set(a.begin(), a.end());
    std::vector<int> coords(unique_sorted_set.begin(), unique_sorted_set.end());

    std::vector<int> compressed(n);
    for (int i = 0; i < n; i++) {
        compressed[i] = std::lower_bound(coords.begin(), coords.end(), a[i]) - coords.begin();
        cout << compressed[i] << " ";
    }
}