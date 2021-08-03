#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    int n = 9, r = 3;
    vector<vector<int>> a, row, col, cub;

    Solver() :
        a(n, vector<int>(n)),
        row(n, vector<int>(n)),
        col(n, vector<int>(n)),
        cub(n, vector<int>(n))
    {}

    bool can(int y, int x, int v) {
        return !row[y][v - 1] && !col[x][v - 1] && !cub[y / r * r + x / r][v - 1];
    }

    void mark(int y, int x, int v, int delta) {
        row[y][v - 1] += delta;
        col[x][v - 1] += delta;
        cub[y / r * r + x / r][v - 1] += delta;
    }

    int solve(int y, int x) {
        if (y == n)
            return 1;
        if (x == n)
            return solve(y + 1, 0);
        if (a[y][x])
            return solve(y, x + 1);

        int res = 0;

        for (int v = 1; v <= n; v++) {
            if (!can(y, x, v))
                continue;

            a[y][x] = v;
            mark(y, x, v, 1);

            int recRes = solve(y, x + 1);
            if (recRes == 2 || recRes == 1 && ++res == 2)
                return 2;

            mark(y, x, v, -1);
            a[y][x] = 0;
        }

        return res;
    }
};

bool solve(int test) {
    Solver solver;
    for (int y = 0; y < solver.n; y++)
        for (int x = 0; x < solver.n; x++)
            if (!(cin >> solver.a[y][x]))
                return 0;
    
    cout << "Case " << test << ": ";
    
    for (int y = 0; y < solver.n; y++) {
        for (int x = 0; x < solver.n; x++) {
            if (!solver.a[y][x])
                continue;
            if (!solver.can(y, x, solver.a[y][x])) {
                cout << "Illegal.\n";
                return 1;
            }
            solver.mark(y, x, solver.a[y][x], 1);
        }
    }

    int res = solver.solve(0, 0);
    if (res == 0)
        cout << "Impossible.\n";
    else if (res == 1)
        cout << "Unique.\n";
    else
        cout << "Ambiguous.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for (int test = 1; solve(test); test++);
}