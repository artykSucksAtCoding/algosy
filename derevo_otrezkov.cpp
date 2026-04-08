#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
const int N = 1e5;

int arr[N];

void build(int v, int tl, int tr, vector<int>& tree) {
    if (tl == tr) {
        tree[v] = arr[tl];
        return;
    }
    int tm = tl + (tr - tl ) / 2;
    build(2*v, tl, tm, tree);
    build(2*v+1, tm+1, tr, tree);
    tree[v] = tree[2*v] + tree[2*v+1];

}

void update(int v, int tl, int tr, int pos, int val, vector<int>&tree) {
    if (tl == tr) {
        tree[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    if (pos <= tm) {
        update(2*v, tl, tm, pos, val, tree);
    } else {
        update(2*v+1, tm+1, tr, pos, val, tree);
    }
    tree[v] = tree[2*v]+tree[2*v+1];
}

int get (int v, int tl, int tr, int ql, int qr, vector<int>&tree) {
    if (tl > qr || tr < ql) {
        return 0;
    }
    if (tl >= ql && tr <=qr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    return get(2*v, tl, tm, ql, qr, tree) + get(2*v+1, tm+1, tr, ql, qr, tree);
}


int main () {
    vector<int> tree(4*N);
    return 0;
}