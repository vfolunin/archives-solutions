#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("matrix.in", "r", stdin);
    freopen("matrix.out", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int matrixCount, size, targetY, targetX, mod;
    cin >> matrixCount >> size >> targetY >> targetX >> mod;
    targetY--;
    targetX--;

    vector<vector<int>> a(size, vector<int>(size));
    for (int y = 0; y < size; y++)
        for (int x = 0; x < size; x++)
            cin >> a[y][x];

    for (int i = 1; i < matrixCount; i++) {
        vector<vector<int>> b(size, vector<int>(size));
        for (int y = 0; y < size; y++)
            for (int x = 0; x < size; x++)
                cin >> b[y][x];

        vector<int> row(size);
        for (int x = 0; x < size; x++)
            for (int j = 0; j < size; j++)
                row[x] = (row[x] + a[targetY][j] * b[j][x]) % mod;

        a[targetY].swap(row);
    }

    cout << a[targetY][targetX];
}