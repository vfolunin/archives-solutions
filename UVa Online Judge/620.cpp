#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int analyze(const string &s, int l, int r) {
    if (l > r)
        return 0;
    if (l == r)
        return s[l] == 'A' ? 1 : 0;
    if (s[r - 1] == 'A' && s[r] == 'B' && analyze(s, l, r - 2))
        return 2;
    if (s[l] == 'B' && s[r] == 'A' && analyze(s, l + 1, r - 1))
        return 3;
    return 0;
}

void solve() {
    string s;
    cin >> s;

    static vector<string> res = { "MUTANT", "SIMPLE", "FULLY-GROWN", "MUTAGENIC" };
    cout << res[analyze(s, 0, s.size() - 1)] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}