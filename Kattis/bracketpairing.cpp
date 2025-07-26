#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getWays(char l, char r) {
    if (l == '(')
        return r == ')' || r == '?';
    if (l == '[')
        return r == ']' || r == '?';
    if (l == '{')
        return r == '}' || r == '?';
    if (l == '<')
        return r == '>' || r == '?';
    if (l == '?') {
        if (r == '?')
            return 4;
        return r == ')' || r == ']' || r == '}' || r == '>';
    }
    return 0;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string s;
    cin >> s;

    vector<vector<long long>> ways(s.size(), vector<long long>(s.size()));
    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            for (int m = l + 1; m <= r; m++) {
                long long cur = getWays(s[l], s[m]);
                if (l + 1 <= m - 1)
                    cur *= ways[l + 1][m - 1];
                if (m + 1 <= r)
                    cur *= ways[m + 1][r];
                ways[l][r] += cur;
            }
        }
    }

    cout << ways[0][s.size() - 1];
}