#include <iostream>

using namespace std;

const int MAX_DIM = 10;

void matmul(int a[][MAX_DIM], int b[][MAX_DIM], int c[][MAX_DIM], int n, int k, int m);

int main() {
    int n;
    int k;
    int m;
    int a[MAX_DIM][MAX_DIM];
    int b[MAX_DIM][MAX_DIM];
    int c[MAX_DIM][MAX_DIM];
    cin >> n >> k >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
        }
    }
    matmul(a, b, c, n, k, m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << c[i][j];
            if (j < m - 1) cout << " ";
        }
        cout << endl;
    }
    return 0;
}

void matmul(int a[][MAX_DIM], int b[][MAX_DIM], int c[][MAX_DIM], int n, int k, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            c[i][j] = 0;
            for (int p = 0; p < k; p++) {
                c[i][j] += a[i][p] * b[p][j];
            }
        }
    }
}
