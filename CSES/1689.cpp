#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;


int getMovesFrom(vector<vector<int>> &a, int y, int x) {
    int res = 0;

    static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && !a[ty][tx])
            res++;
    }

    return res;
}

void rec(vector<vector<int>> &a, int y, int x, int i) {
    a[y][x] = i;

    if (i == a.size() * a.size()) {
        for (int y = 0; y < a.size(); y++) {
            for (int x = 0; x < a.size(); x++)
                cout << a[y][x] << " ";
            cout << "\n";
        }
        exit(0);
    }

    static vector<int> dy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    static vector<int> dx = { -1, 1, 2, 2, 1, -1, -2, -2 };
    vector<pair<int, int>> to;

    for (int d = 0; d < dy.size(); d++) {
        int ty = y + dy[d];
        int tx = x + dx[d];

        if (0 <= ty && ty < a.size() && 0 <= tx && tx < a.size() && !a[ty][tx])
            to.push_back({ ty, tx });
    }

    sort(to.begin(), to.end(), [&](auto &lhs, auto &rhs) {
        return getMovesFrom(a, lhs.first, lhs.second) < getMovesFrom(a, rhs.first, rhs.second);
    });

    for (auto &[ty, tx] : to)
        rec(a, ty, tx, i + 1);

    a[y][x] = 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int y, x;
    cin >> x >> y;

    vector<vector<int>> a(8, vector<int>(8));
    rec(a, y - 1, x - 1, 1);
}