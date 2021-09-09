#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    map<string, int> tiles;
    vector<vector<const string *>> solution;
    int solutionCount = 0;

    Solver() : solution(4, vector<const string *>(3)) {}

    void add(string &tile) {
        tiles[tile]++;
    }

    void rec(int y, int x, int factor) {
        if (y == 4) {
            solutionCount += factor;
            return;
        }
        
        if (x == 3) {
            rec(y + 1, 0, factor);
            return;
        }

        for (auto &[tile, k] : tiles) {
            if (!k || y && tile[0] != (*solution[y - 1][x])[2] || x && tile[3] != (*solution[y][x - 1])[1])
                continue;
            k--;
            solution[y][x] = &tile;
            rec(y, x + 1, factor * (k + 1));
            k++;
        }
    }
};

void solve(int test) {
    Solver solver;

    for (int i = 0; i < 12; i++) {
        string tile;
        cin >> tile;
        solver.add(tile);
    }

    solver.rec(0, 0, 1);

    cout << "Case " << test << ": " << solver.solutionCount << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}