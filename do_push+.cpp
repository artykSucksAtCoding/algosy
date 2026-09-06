#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
const int N = 1e5;

int arr[N];

void build(int v, int tl, int tr, vector<ll>& tree) {
    if (tl == tr) {
        tree[v] = arr[tl];
        return;
    }
    int tm = tl + (tr - tl ) / 2;
    build(2*v, tl, tm, tree);
    build(2*v+1, tm+1, tr, tree);
    tree[v] = tree[2*v] + tree[2*v+1];

}

void push (int v, int tl, int tr, vector<ll>& tree, vector<ll>& pro) {
    if (!pro[v]) return;

    int x = pro[v];
    int tm = (tl + tr) / 2;

    tree[2*v] += x*(tm-tl+1);
    pro[2*v] += pro[v];

    tree[2*v+1] += x*(tr - tm);
    pro[2*v+1] += pro[v];
    pro[v] = 0;

}

void update (int v, int tl, int tr, int ql, int qr, ll val, vector<ll>&tree, vector<ll>& pro) {
    if (tl > qr || tr < ql) {
        return;
    }
    if (tl >= ql && tr <=qr) {
        tree[v] += val*(tr-tl+1);
        pro[v]+=val;
        return;
    }
    push(v, tl, tr, tree, pro);
    int tm = (tl + tr) / 2;
    update(2*v, tl, tm, ql, qr, val, tree, pro);
    update(2*v+1, tm+1, tr, ql, qr, val, tree, pro);
    tree[v] = tree[2*v]+tree[2*v+1];
}



ll get (int v, int tl, int tr, int ql, int qr, vector<ll>&tree, vector<ll>& pro) {
    if (tl > qr || tr < ql) {
        return 0;
    }
    if (tl >= ql && tr <=qr) {
        return tree[v];
    }
    push(v, tl, tr, tree, pro);
    int tm = (tl + tr) / 2;
    return get(2*v, tl, tm, ql, qr, tree, pro) + get(2*v+1, tm+1, tr, ql, qr, tree, pro);
}


int main () {
    vector<ll> tree(4*N);
    vector<ll> pro(4*N, 0);
    n = 4;
    arr[0] = 1;
    arr[1] = 2;
    arr[2] = 3;
    arr[3] = 4;

    return 0;
}