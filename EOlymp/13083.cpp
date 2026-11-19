#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s >> s;

    vector<int> l(s.size(), 1);
    for (int i = 1; i < s.size(); i++)
        if (s[i - 1] <= s[i])
            l[i] = l[i - 1] + 1;

    vector<int> r(s.size(), 1);
    for (int i = (int)s.size() - 2; i >= 0; i--)
        if (s[i] <= s[i + 1])
            r[i] = r[i + 1] + 1;

    int res = min<int>(max(*max_element(l.begin(), l.end()), *max_element(r.begin(), r.end())) + 1, s.size());
    for (int i = 1; i + 1 < s.size(); i++)
        if (s[i - 1] <= s[i + 1])
            res = max(res, l[i - 1] + 1 + r[i + 1]);

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}