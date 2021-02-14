#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    vector<pair<int, int>> coeff;
    for (int p = 8; p >= 0; p--) {
        int c;
        if (!(cin >> c))
            return 0;
        if (c)
            coeff.push_back({ p, c });
    }

    if (coeff.empty()) {
        cout << "0\n";
        return 1;
    }

    bool first = 1;
    for (auto &[p, c] : coeff) {
        bool neg = c < 0;
        c = abs(c);

        if (first) {
            first = 0;
            if (neg)
                cout << "-";
        } else {
            cout << (neg ? " - " : " + ");
        }

        if (p) {
            if (c > 1)
                cout << c;
            cout << "x";
            if (p > 1)
            cout << "^" << p;
        } else {
            cout << c;
        }
    }
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}