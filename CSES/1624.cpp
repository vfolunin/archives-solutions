#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    vector<string> a;
    vector<int> cols, d1, d2;
    long long res;
    
    Solver() : a(8), cols(8), d1(15), d2(15) {}

    void rec(int row) {
        if (row == 8) {
            res++;
            return;
        }

        for (int col = 0; col < 8; col++) {
            if (a[row][col] == '*' || cols[col] || d1[row + col] || d2[row - col + 7])
                continue;

            cols[col] = d1[row + col] = d2[row - col + 7] = 1;
            rec(row + 1);
            cols[col] = d1[row + col] = d2[row - col + 7] = 0;
        }
    }

    int rec() {
        res = 0;
        rec(0);
        return res;
    }
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    Solver solver;
    for (string &row : solver.a)
        cin >> row;

    cout << solver.rec();
}