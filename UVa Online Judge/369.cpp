#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    const int N = 1000;
    vector<vector<long long>> c(N, vector<long long>(N));
    c[0][0] = 1;

    for (int i = 1; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++)
            c[i][j] = c[i - 1][j - 1] + c[i - 1][j];
    }

    while (1) {
        int n, m;
        cin >> n >> m;
        if (!n && !m)
            break;

        cout << n << " things taken " << m << " at a time is " << c[n][m] << " exactly.\n";
    }
}