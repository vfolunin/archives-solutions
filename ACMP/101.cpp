#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int targetCount, int y, vector<int> &col, vector<int> &d1, vector<int> &d2, vector<vector<int>> &cell) {
    if (!targetCount)
        return 1;

    if (y == cell.size())
        return 0;

    int res = rec(targetCount, y + 1, col, d1, d2, cell);

    static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    for (int x = 0; x < col.size(); x++) {
        if (col[x] || d1[y + x] || d2[y - x + col.size()] || cell[y][x])
            continue;

        col[x] = d1[y + x] = d2[y - x + col.size()] = 1;

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < cell.size() && 0 <= tx && tx < cell.size())
                cell[ty][tx]++;
        }

        res += rec(targetCount - 1, y + 1, col, d1, d2, cell);

        col[x] = d1[y + x] = d2[y - x + col.size()] = 0;

        for (int d = 0; d < dy.size(); d++) {
            int ty = y + dy[d];
            int tx = x + dx[d];

            if (0 <= ty && ty < cell.size() && 0 <= tx && tx < cell.size())
                cell[ty][tx]--;
        }
    }

    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, targetCount;
    cin >> size >> targetCount;

    vector<int> col(size), d1(size * 2), d2(size * 2);
    vector<vector<int>> cell(size, vector<int>(size));
    cout << rec(targetCount, 0, col, d1, d2, cell);
}