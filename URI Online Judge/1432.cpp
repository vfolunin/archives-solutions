#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(string &s, int i) {
    if (i == s.size())
        return 1;

    if (s[i] != '*') {
        bool ok = 1;
        for (int len = 1; ok && i - 3 * len + 1 >= 0; len++)
            ok &= s.substr(i - len + 1, len) != s.substr(i - 2 * len + 1, len) ||
            s.substr(i - len + 1, len) != s.substr(i - 3 * len + 1, len);
        return ok ? rec(s, i + 1) : 0;
    }

    int res = 0;
    for (s[i] = '0'; s[i] <= '1'; s[i]++) {
        bool ok = 1;
        for (int len = 1; ok && i - 3 * len + 1 >= 0; len++)
            ok &= s.substr(i - len + 1, len) != s.substr(i - 2 * len + 1, len) ||
            s.substr(i - len + 1, len) != s.substr(i - 3 * len + 1, len);
        if (ok)
            res += rec(s, i + 1);
    }
    s[i] = '*';
    return res;
}

bool solve(int test) {
    string s;
    if (!(cin >> s >> s))
        return 0;

    cout << "Case " << test << ": " << rec(s, 0) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}