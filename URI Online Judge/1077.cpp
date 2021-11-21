#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    string ops;
    for (char c : s) {
        if (isdigit(c) || isalpha(c)) {
            cout << c;
        } else if (c == '(') {
            ops.push_back(c);
        } else if (c == ')') {
            while (ops.back() != '(') {
                cout << ops.back();
                ops.pop_back();
            }
            ops.pop_back();
        } else if (c == '^') {
            ops.push_back(c);
        } else if (c == '*' || c == '/') {
            while (!ops.empty() && string("*/^").find(ops.back()) != -1) {
                cout << ops.back();
                ops.pop_back();
            }
            ops.push_back(c);
        } else if (c == '+' || c == '-') {
            while (!ops.empty() && string("+-*/^").find(ops.back()) != -1) {
                cout << ops.back();
                ops.pop_back();
            }
            ops.push_back(c);
        }
    }

    while (!ops.empty()) {
        cout << ops.back();
        ops.pop_back();
    }
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}