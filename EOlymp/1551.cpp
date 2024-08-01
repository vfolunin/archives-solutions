#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isOpen(char c) {
    return c == '(' || c == '[' || c == '{';
}

char complement(char c) {
    if (c == '(')
        return ')';
    else if (c == '[')
        return ']';
    else
        return '}';
}

int getPrice(char a, char b) {
    if (!isOpen(a) && isOpen(b))
        return 2;
    else if (!isOpen(a) || isOpen(b))
        return 1;
    else
        return b != complement(a);
}

bool solve() {
    string s;
    if (!(cin >> s))
        return 0;

    vector<vector<int>> cost(s.size(), vector<int>(s.size()));
    for (int len = 2; len <= s.size(); len += 2) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            cost[l][r] = 1e9;
            for (int m = l + 1; m < r; m += 2)
                cost[l][r] = min(cost[l][r], cost[l][m] + cost[m + 1][r]);
            cost[l][r] = min(cost[l][r], cost[l + 1][r - 1] + getPrice(s[l], s[r]));
        }
    }

    cout << cost[0][s.size() - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}