#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Solver {
    int index, limit;
    string s;

    bool check() {
        for (int size = 1; size * 2 <= s.size(); size++) {
            for (int from = 0; from + 2 * size <= s.size(); from++) {
                bool eq = 1;
                for (int i = from, j = from + size; eq && i < from + size; i++, j++)
                    eq &= s[i] == s[j];
                if (eq)
                    return 0;
            }
        }
        return 1;
    }

    void inc() {
        s += 'A';
        if (check())
            return;

        while (1) {
            while (s.back() < 'A' + limit - 1) {
                s.back()++;
                if (check())
                    return;
            }

            while (s.back() == 'A' + limit - 1)
                s.pop_back();
        }
    }

    string solve() {
        for (int i = 0; i < index; i++)
            inc();
        return s;
    }
};

bool solve() {
    Solver solver;
    cin >> solver.index >> solver.limit;

    if (!solver.index && !solver.limit)
        return 0;

    string res = solver.solve();

    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i + 1 == res.size() || i % 64 == 63)
            cout << "\n";
        else if (i % 4 == 3)
            cout << " ";
    }
    cout << res.size() << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}