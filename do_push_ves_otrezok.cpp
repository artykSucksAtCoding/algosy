#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int n;
const int N = 1e5;
const int I = 1e9+5;

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

void push (int v, int tl, int tr, vector<int>& pro, vector<int>& tree) {
    if (pro[v] == I) return;
 
    int tm = (tl + tr) / 2;
    tree[2*v] = pro[v]*(tm-tl+1);
    tree[2*v+1] = pro[v]*(tr-tm);
    pro[2*v] = pro[2*v+1] = pro[v];
    pro[v] = I;
}

void assign (int v, int tl, int tr, int ql, int qr, int val, vector<int>& pro, vector<int>&tree) {
    if (tl > qr || tr < ql) {
        return;
    }
    if (tl >= ql && tr <=qr) {
        tree[v] = val*(tr-tl+1);
        pro[v] = val;
        return;
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tr, pro, tree);
    assign(2*v, tl, tm, ql, qr, val, pro, tree);
    assign(2*v+1, tm+1, tr, ql, qr, val, pro, tree);
    tree[v] = tree[2*v]+tree[2*v+1];
}



int get (int v, int tl, int tr, int ql, int qr, vector<int>& pro, vector<int>&tree) {
    if (tl > qr || tr < ql) {
        return 0;
    }
    if (tl >= ql && tr <=qr) {
        return tree[v];
    }
    int tm = (tl + tr) / 2;
    push(v, tl, tr, pro, tree);
    return get(2*v, tl, tm, ql, qr, pro, tree) + get(2*v+1, tm+1, tr, ql, qr, pro, tree);
}


int main () {
    vector<int> tree(4*N);
    vector<int> pro(4*N, I);
    return 0;
}