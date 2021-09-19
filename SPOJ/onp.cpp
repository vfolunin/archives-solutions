#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

string rpn(string &s, int l, int r) {
    int d = 0, p1 = -1, p2 = -1, p3 = -1;
    for (int i = l; i <= r; i++) {
        if (s[i] == '(')
            d++;
        if (s[i] == ')')
            d--;
        if (!d) {
            if (s[i] == '+' || s[i] == '-')
                p1 = i;
            if (s[i] == '*' || s[i] == '/')
                p2 = i;
            if (s[i] == '^' && p3 == -1)
                p3 = i;
        }
    }

    if (p1 != -1) {
        if (s[p1] == '+')
            return rpn(s, l, p1 - 1) + rpn(s, p1 + 1, r) + "+";
        else
            return rpn(s, l, p1 - 1) + rpn(s, p1 + 1, r) + "-";
    }

    if (p2 != -1) {
        if (s[p2] == '*')
            return rpn(s, l, p2 - 1) + rpn(s, p2 + 1, r) + "*";
        else
            return rpn(s, l, p2 - 1) + rpn(s, p2 + 1, r) + "/";
    }

    if (p3 != -1)
        return rpn(s, l, p3 - 1) + rpn(s, p3 + 1, r) + "^";

    if (s[l] == '(' && s[r] == ')')
        return rpn(s, l + 1, r - 1);

    return string(1, s[l]);
}

void solve() {
    string line;
    cin >> line;

    cout << rpn(line, 0, line.size() - 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}