#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int sum(vector<vector<int>> &p, int ly, int ry, int lx, int rx) {
    int res = p[ry][rx];
    if (ly)
        res -= p[ly - 1][rx];
    if (lx)
        res -= p[ry][lx - 1];
    if (ly && lx)
        res += p[ly - 1][lx - 1];
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, queryCount;
    cin >> size >> queryCount;

    vector<vector<int>> p(size, vector<int>(size));

    for (int y = 0; y < size; y++) {
        string line;
        cin >> line;

        for (int x = 0; x < size; x++) {
            p[y][x] = line[x] == '*';
            if (y)
                p[y][x] += p[y - 1][x];
            if (x)
                p[y][x] += p[y][x - 1];
            if (y && x)
                p[y][x] -= p[y - 1][x - 1];
        }
    }

    for (int i = 0; i < queryCount; i++) {
        int y1, x1, y2, x2;
        cin >> y1 >> x1 >> y2 >> x2;

        cout << sum(p, y1 - 1, y2 - 1, x1 - 1, x2 - 1) << "\n";
    }
}