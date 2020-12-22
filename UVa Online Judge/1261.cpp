#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int rec(string pattern, map<string, int> &memo) {
    if (memo.count(pattern))
        return memo[pattern];

    if (pattern.size() == 1)
        return memo[pattern] = pattern[0] == '1';

    for (int i = 0; i < pattern.size(); i++) {
        if (pattern[i] == '1') {
            string nextPattern;
            if (0 < i && i + 1 < pattern.size())
                nextPattern = pattern.substr(0, i - 1) + '1' + pattern.substr(i + 2);
            else
                nextPattern = pattern.substr(0, i) + pattern.substr(i + 1);
            if (rec(nextPattern, memo) == 1)
                return 1;
        }
    }

    return memo[pattern] = 0;
}

void solve(int test) {
    string s;
    cin >> s;

    string pattern;
    for (int i = 0; i < s.size(); i++) {
        if (i == 0 || s[i] != s[i - 1])
            pattern += '0';
        else if (pattern.back() == '0')
            pattern.back()++;
    }

    map<string, int> memo;
    cout << rec(pattern, memo) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}