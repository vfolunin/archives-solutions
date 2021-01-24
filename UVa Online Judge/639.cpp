#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void mark(int n, vector<string> &a, int y, int x, int delta) {
    static int dy[] = { -1, 0, 1, 0 };
    static int dx[] = { 0, 1, 0, -1 };

    for (int d = 0; d < 4; d++) {
        for (int step = 1; 1; step++) {
            int ty = y + dy[d] * step, tx = x + dx[d] * step;
            if (0 <= ty && ty < n && 0 <= tx && tx < n && a[ty][tx] != 'X')
                a[ty][tx] += delta;
            else
                break;
        }
    }
}

void rec(int n, vector<string> &a, int i, int curRes, int &maxRes) {
    if (i == n * n) {
        maxRes = max(maxRes, curRes);
        return;
    }

    int y = i / n, x = i % n;
    rec(n, a, i + 1, curRes, maxRes);
    if (a[y][x] == '.') {
        mark(n, a, y, x, 1);
        rec(n, a, i + 1, curRes + 1, maxRes);
        mark(n, a, y, x, -1);
    }
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<string> a(n);
    for (string &row : a)
        cin >> row;

    int maxRes = 0;
    rec(n, a, 0, 0, maxRes);

    cout << maxRes << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}