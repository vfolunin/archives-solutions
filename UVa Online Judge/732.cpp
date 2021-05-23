#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    string a, b, stack, ops;
    int ai, bi;

    void rec(int ai, int bi) {
        if (bi == b.size()) {
            for (int i = 0; i < ops.size(); i++)
                cout << ops[i] << (i + 1 < ops.size() ? " " : "\n");
            return;
        }

        if (ai < a.size()) {
            ops.push_back('i');
            stack.push_back(a[ai]);
            rec(ai + 1, bi);
            stack.pop_back();
            ops.pop_back();
        }

        if (!stack.empty() && bi < b.size() && stack.back() == b[bi]) {
            ops.push_back('o');
            stack.pop_back();
            rec(ai, bi + 1);
            stack.push_back(b[bi]);
            ops.pop_back();
        }
    }
};

bool solve() {
    static Solver solver;
    if (!(cin >> solver.a >> solver.b))
        return 0;

    cout << "[\n";
    solver.rec(0, 0);
    cout << "]\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}