#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    vector<string> a(size);
    for (string &row : a)
        cin >> row;

    vector<vector<int>> square(size, vector<int>(size));
    vector<vector<int>> triangleUp(size, vector<int>(size));
    vector<vector<int>> triangleDown(size, vector<int>(size));
    vector<vector<int>> rhombus(size, vector<int>(size));
    int res = 0;

    for (int y = 0; y < size; y++) {
        for (int x = 0; x < size; x++) {
            if (a[y][x] == '.')
                continue;

            square[y][x] = 1;
            if (y && x)
                square[y][x] = min(min(square[y - 1][x], square[y][x - 1]), square[y - 1][x - 1]) + 1;

            res += square[y][x] - 1;

            triangleUp[y][x] = 1;
            if (y && x && x + 1 < size)
                triangleUp[y][x] = min(min(triangleUp[y - 1][x - 1], triangleUp[y - 1][x]), triangleUp[y - 1][x + 1]) + 1;
        }
    }

    for (int y = size - 1; y >= 0; y--) {
        for (int x = 0; x < size; x++) {
            if (a[y][x] == '.')
                continue;

            triangleDown[y][x] = 1;
            if (y + 1 < size && x && x + 1 < size)
                triangleDown[y][x] = min(min(triangleDown[y + 1][x - 1], triangleDown[y + 1][x]), triangleDown[y + 1][x + 1]) + 1;

            int l = 1, r = size;
            while (l + 1 < r) {
                int m = l + (r - l) / 2, h = 2 * m - 1;
                if (y + h - 1 < size && triangleDown[y][x] + triangleUp[y + h - 1][x] >= h)
                    l = m;
                else
                    r = m;
            }
            rhombus[y][x] = 2 * l - 1;

            res += rhombus[y][x] / 2;
        }
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}