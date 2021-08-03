#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    vector<vector<int>> a, b;
    int res = 0;
    vector<int> used;

    inline static const vector<int> bones = {
        0, 1, 2, 3, 4, 5, 6,
        11, 12, 13, 14, 15, 16, 22,
        23, 24, 25, 26, 33, 34, 35,
        36, 44, 45, 46, 55, 56, 66
    };

    Solver() {
        a.assign(7, vector<int>(8));
        b.assign(7, vector<int>(8));
        used.resize(28);
    }

    void rec(int y, int x) {
        if (y == 7) {
            res++;
            for (int y = 0; y < 7; y++) {
                for (int x = 0; x < 8; x++)
                    cout << setw(4) << b[y][x];
                cout << "\n";
            }
            cout << "\n\n";
            return;
        }

        if (x == 8) {
            rec(y + 1, 0);
            return;
        }

        if (b[y][x]) {
            rec(y, x + 1);
            return;
        }

        static int dy[] = { 1, 0 }, dx[] = { 0, 1 };
        for (int d = 0; d < 2; d++) {
            int ty = y + dy[d], tx = x + dx[d];
            if (ty == 7 || tx == 8 || b[ty][tx])
                continue;

            int boneValue = min(a[y][x], a[ty][tx]) * 10 + max(a[y][x], a[ty][tx]);
            int bone = lower_bound(bones.begin(), bones.end(), boneValue) - bones.begin();
            if (used[bone])
                continue;

            used[bone] = 1;
            b[y][x] = b[ty][tx] = bone + 1;
            rec(y, x + 1);
            used[bone] = 0;
            b[y][x] = b[ty][tx] = 0;
        }
    }

};

bool solve(int test) {
    Solver solver;

    for (int y = 0; y < 7; y++)
        for (int x = 0; x < 8; x++)
            if (!(cin >> solver.a[y][x]))
                return 0;

    if (test > 1)
        cout << "\n\n\n\n\n";

    cout << "Layout #" << test << ":\n\n\n";

    for (int y = 0; y < 7; y++) {
        for (int x = 0; x < 8; x++)
            cout << setw(4) << solver.a[y][x];
        cout << "\n";
    }

    cout << "\nMaps resulting from layout #" << test << " are:\n\n\n";
    solver.rec(0, 0);

    cout << "There are " << solver.res << " solution(s) for layout #" << test << ".\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}