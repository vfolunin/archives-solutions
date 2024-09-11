#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int eval(string &s, int l, int r) {
    int p1 = -1, p2 = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '+' || s[i] == '-')
            p1 = i;
        if (s[i] == '*' || s[i] == '/')
            p2 = i;
    }

    if (p1 != -1) {
        if (s[p1] == '+')
            return eval(s, l, p1 - 2) + eval(s, p1 + 2, r);
        else
            return eval(s, l, p1 - 2) - eval(s, p1 + 2, r);
    }

    if (p2 != -1) {
        if (s[p2] == '*') {
            return eval(s, l, p2 - 2) * eval(s, p2 + 2, r);
        } else {
            return eval(s, l, p2 - 2) / eval(s, p2 + 2, r);
        }
    }

    return stoi(s.substr(l, r - l + 1));
}

void solve() {
    int n;
    cin >> n;

    string eq = "4 o 4 o 4 o 4", ops = "+-*/";

    for (int a = 0; a < 4; a++) {
        eq[2] = ops[a];
        for (int b = 0; b < 4; b++) {
            eq[6] = ops[b];
            for (int c = 0; c < 4; c++) {
                eq[10] = ops[c];

                if (eval(eq, 0, eq.size() - 1) == n) {
                    cout << eq << " = " << n << "\n";
                    return;
                }

            }
        }
    }

    cout << "no solution\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}