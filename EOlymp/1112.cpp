#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    char qy, qx, ry, rx, ny, nx;
    for (int i = 0; i < 3; i++) {
        char type;
        cin >> type;

        if (type == 'Q') {
            cin >> qx >> qy;
            qx -= 'a';
            qy -= '1';
        } else if (type == 'R') {
            cin >> rx >> ry;
            rx -= 'a';
            ry -= '1';
        } else {
            cin >> nx >> ny;
            nx -= 'a';
            ny -= '1';
        }
    }

    vector<vector<int>> a(8, vector<int>(8));

    vector<int> qdy = { -1, -1, -1, 0, 1, 1, 1, 0 };
    vector<int> qdx = { -1, 0, 1, 1, 1, 0, -1, -1 };

    for (int d = 0; d < qdy.size(); d++) {
        for (int step = 1; step < a.size(); step++) {
            int ty = qy + qdy[d] * step;
            int tx = qx + qdx[d] * step;

            if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a.size() ||
                ty == ry && tx == rx || ty == ny && tx == nx)
                break;

            a[ty][tx] = 1;
        }
    }

    vector<int> rdy = { -1, 0, 1, 0 };
    vector<int> rdx = { 0, 1, 0, -1 };

    for (int d = 0; d < rdy.size(); d++) {
        for (int step = 1; step < a.size(); step++) {
            int ty = ry + rdy[d] * step;
            int tx = rx + rdx[d] * step;

            if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a.size() ||
                ty == qy && tx == qx || ty == ny && tx == nx)
                break;

            a[ty][tx] = 1;
        }
    }

    vector<int> ndy = { -2, -2, -1, 1, 2, 2, 1, -1 };
    vector<int> ndx = { -1, 1, 2, 2, 1, -1, -2, -2 };

    for (int d = 0; d < ndy.size(); d++) {
        int ty = ny + ndy[d];
        int tx = nx + ndx[d];

        if (ty < 0 || ty >= a.size() || tx < 0 || tx >= a.size() ||
            ty == qy && tx == qx || ty == ry && tx == rx)
            continue;

        a[ty][tx] = 1;
    }

    int res = 0;
    for (int y = 0; y < a.size(); y++)
        for (int x = 0; x < a.size(); x++)
            res += a[y][x];

    cout << res;
}