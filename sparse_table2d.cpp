#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int N = 1e3+1;
const int LOG_N = 10; // логарифмы сверху
const int LOG_M = 10;
int n;
int m;
int q;
int arr[N][N];
int sparse[LOG_N][LOG_M][N][N];
int deg[N];

void build() {
    deg[1] = 0;
    for (int i = 2; i <= N; i++) {
        deg[i] = deg[i-1];
        if (!(i & (i-1))) {
            ++deg[i];
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < m; j++) {
            sparse[0][0][i][j] = arr[i][j];
        }
    }


    for (int k1 = 0; k1 < LOG_M - 1; k1++) {
        int help = (1 << k1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j + (1 << (k1 + 1)) <= m; j++) {
                sparse[0][k1 + 1][i][j] = min(sparse[0][k1][i][j], sparse[0][k1][i][j + help]);
            }
        }
    }


    for (int k2 = 0; k2 < LOG_N - 1; k2++) {
        int help = (1 << k2);
        for (int k1 = 0; k1 < LOG_M; k1++) {

            for (int i = 0; i + (1 << (k2 + 1)) <= n; i++) {
                for (int j = 0; j < m; j++) {
                    sparse[k2 + 1][k1][i][j] = min(sparse[k2][k1][i][j], sparse[k2][k1][i + help][j]);
                }
            }
        }
    }
}

int get_min(int x1, int y1, int x2, int y2) {
    int kx = deg[x2 - x1 + 1];
    int ky = deg[y2 - y1 + 1];
    int m1 = sparse[kx][ky][x1][y1];
    int m2 = sparse[kx][ky][x2 - (1 << kx) + 1][y1];
    int m3 = sparse[kx][ky][x1][y2 - (1 << ky) + 1];
    int m4 = sparse[kx][ky][x2 - (1 << kx) + 1][y2 - (1 << ky) + 1];
    return min({m1, m2, m3, m4});
}


int main () {
    cin >> n >> m >> q;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }
    build();

    for (int i = 0; i < q; i++) {
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        cout << get_min(l1-1, r1-1, l2-1, r2-1) << "\n";
    }
}