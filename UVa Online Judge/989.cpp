#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    int n, r;
    vector<vector<int>> a, row, col, cub;

    bool can(int y, int x, int v) {
        return !row[y][v - 1] && !col[x][v - 1] && !cub[y / r * r + x / r][v - 1];
    }

    void mark(int y, int x, int v, int delta) {
        row[y][v - 1] += delta;
        col[x][v - 1] += delta;
        cub[y / r * r + x / r][v - 1] += delta;
    }

    bool solve(int y, int x) {
        if (y == n)
            return 1;
        if (x == n)
            return solve(y + 1, 0);
        if (a[y][x])
            return solve(y, x + 1);

        for (int v = 1; v <= n; v++) {
            if (!can(y, x, v))
                continue;
            a[y][x] = v;
            mark(y, x, v, 1);
            if (solve(y, x + 1))
                return 1;
            mark(y, x, v, -1);
            a[y][x] = 0;
        }

        return 0;
    }
};

bool solve(int test) {
    Solver solver;
    if (!(cin >> solver.r))
        return 0;

    solver.n = solver.r * solver.r;
    solver.a.assign(solver.n, vector<int>(solver.n));
    solver.row.assign(solver.n, vector<int>(solver.n));
    solver.col.assign(solver.n, vector<int>(solver.n));
    solver.cub.assign(solver.n, vector<int>(solver.n));

    for (int y = 0; y < solver.n; y++) {
        for (int x = 0; x < solver.n; x++) {
            cin >> solver.a[y][x];
            if (solver.a[y][x])
                solver.mark(y, x, solver.a[y][x], 1);
        }
    }

    if (test)
        cout << "\n";
    if (solver.solve(0, 0)) {
        for (int y = 0; y < solver.n; y++)
            for (int x = 0; x < solver.n; x++)
                cout << solver.a[y][x] << (x + 1 < solver.n ? " " : "\n");
    } else {
        cout << "NO SOLUTION\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; solve(i); i++);
}