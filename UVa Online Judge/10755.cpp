#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long sum(vector<vector<vector<long long>>> &p, int z1, int z2, int y1, int y2, int x1, int x2) {
    long long res = p[z2][y2][x2];
    if (z1)
        res -= p[z1 - 1][y2][x2];
    if (y1)
        res -= p[z2][y1 - 1][x2];
    if (x1)
        res -= p[z2][y2][x1 - 1];
    if (z1 && y1)
        res += p[z1 - 1][y1 - 1][x2];
    if (z1 && x1)
        res += p[z1 - 1][y2][x1 - 1];
    if (y1 && x1)
        res += p[z2][y1 - 1][x1 - 1];
    if (z1 && y1 && x1)
        res -= p[z1 - 1][y1 - 1][x1 - 1];
    return res;
}

void solve(int test) {
    int zSize, ySize, xSize;
    cin >> zSize >> ySize >> xSize;

    vector<vector<vector<long long>>> p(zSize, vector<vector<long long>>(ySize, vector<long long>(xSize)));
    for (int z = 0; z < zSize; z++) {
        for (int y = 0; y < ySize; y++) {
            for (int x = 0; x < xSize; x++) {
                cin >> p[z][y][x];
                if (z)
                    p[z][y][x] += p[z - 1][y][x];
                if (y)
                    p[z][y][x] += p[z][y - 1][x];
                if (x)
                    p[z][y][x] += p[z][y][x - 1];
                if (z && y)
                    p[z][y][x] -= p[z - 1][y - 1][x];
                if (z && x)
                    p[z][y][x] -= p[z - 1][y][x - 1];
                if (y && x)
                    p[z][y][x] -= p[z][y - 1][x - 1];
                if (z && y && x)
                    p[z][y][x] += p[z - 1][y - 1][x - 1];
            }
        }
    }

    long long res = -(1LL << 60);
    for (int z1 = 0; z1 < zSize; z1++)
        for (int z2 = z1; z2 < zSize; z2++)
            for (int y1 = 0; y1 < ySize; y1++)
                for (int y2 = y1; y2 < ySize; y2++)
                    for (int x1 = 0; x1 < xSize; x1++)
                        for (int x2 = x1; x2 < xSize; x2++)
                            res = max(res, sum(p, z1, z2, y1, y2, x1, x2));

    if (test)
        cout << "\n";
    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}