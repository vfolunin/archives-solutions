#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
using namespace std;

void mark(vector<string> &a, int y, int x, const vector<int> &dy, const vector<int> &dx, bool jump) {
    for (int d = 0; d < dy.size(); d++) {
        for (int step = 1; step <= 1 || !jump; step++) {
            int ty = y + dy[d] * step, tx = x + dx[d] * step;
            if (ty < 0 || ty > 7 || tx < 0 || tx > 7 || a[ty][tx] != '.' && a[ty][tx] != 'x')
                break;
            a[ty][tx] = 'x';
        }
    }
}

bool solve() {
    string fen;
    if (!(cin >> fen))
        return 0;

    vector<string> a(8, string(8, '.'));
    for (int y = 0, x = 0, i = 0; i < fen.size(); i++) {
        if (isdigit(fen[i])) {
            x += fen[i] - '0';
        } else if (fen[i] == '/') {
            y++;
            x = 0;
        } else {
            a[y][x++] = fen[i];
        }
    }

    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            if (a[y][x] == 'K' || a[y][x] == 'k')
                mark(a, y, x, { -1, -1, -1, 0, 1, 1, 1, 0 }, { -1, 0, 1, 1, 1, 0, -1, -1 }, 1);
            if (a[y][x] == 'Q' || a[y][x] == 'q')
                mark(a, y, x, { -1, -1, -1, 0, 1, 1, 1, 0 }, { -1, 0, 1, 1, 1, 0, -1, -1 }, 0);
            if (a[y][x] == 'R' || a[y][x] == 'r')
                mark(a, y, x, { -1, 0, 1, 0 }, { 0, 1, 0, -1 }, 0);
            if (a[y][x] == 'B' || a[y][x] == 'b')
                mark(a, y, x, { -1, -1, 1, 1 }, { -1, 1, 1, -1 }, 0);
            if (a[y][x] == 'N' || a[y][x] == 'n')
                mark(a, y, x, { -2, -2, -1, 1, 2, 2, 1, -1 }, { -1, 1, 2, 2, 1, -1, -2, -2 }, 1);
            if (a[y][x] == 'P')
                mark(a, y, x, { -1, -1 }, { -1, 1 }, 1);
            if (a[y][x] == 'p')
                mark(a, y, x, { 1, 1 }, { -1, 1 }, 1);
        }
    }

    int res = 0;
    for (string &row : a)
        res += count(row.begin(), row.end(), '.');

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}