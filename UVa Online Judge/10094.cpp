#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    vector<int> placement, usedRow, usedD1, usedD2;

    bool rec(int size, int col) {
        if (col == size)
            return 1;

        if (size > 10 && 2 * col + 5 < size) {
            int row = 2 * col + 5;

            usedRow[row]++;
            usedD1[row + col]++;
            usedD2[row - col + size]++;

            placement[col] = row;
            if (rec(size, col + 1))
                return 1;

            usedRow[row]--;
            usedD1[row + col]--;
            usedD2[row - col + size]--;

            return 0;
        }

        for (int row = 0; row < size; row++) {
            if (usedRow[row] || usedD1[row + col] || usedD2[row - col + size])
                continue;

            usedRow[row]++;
            usedD1[row + col]++;
            usedD2[row - col + size]++;

            placement[col] = row;
            if (rec(size, col + 1))
                return 1;

            usedRow[row]--;
            usedD1[row + col]--;
            usedD2[row - col + size]--;
        }

        return 0;
    }

    bool getPlacement(int size) {
        placement.resize(size);
        usedRow.resize(size);
        usedD1.resize(size * 2);
        usedD2.resize(size * 2);
        return rec(size, 0);
    }
};

bool solve() {
    int size;
    if (!(cin >> size))
        return 0;

    Solver solver;
    if (!solver.getPlacement(size)) {
        cout << "Impossible\n";
    } else {
        for (int i = 0; i < size; i++)
            cout << solver.placement[i] + 1 << (i + 1 < size ? " " : "\n");
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}