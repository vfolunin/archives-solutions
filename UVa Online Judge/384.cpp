#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool isSlump(string &s, int l, int r) {
    if (r - l + 1 < 3)
        return 0;

    if (s[l] != 'D' && s[l] != 'E')
        return 0;

    int fCount = 0;
    while (l + 1 + fCount <= r && s[l + 1 + fCount] == 'F')
        fCount++;
    if (fCount < 1)
        return 0;

    return l + 1 + fCount == r && s[r] == 'G' || isSlump(s, l + 1 + fCount, r);
}

bool isSlimp(string &s, int l, int r) {
    if (r - l + 1 < 2)
        return 0;

    if (s[l] != 'A')
        return 0;

    if (l + 1 == r)
        return s[r] == 'H';

    return (s[l + 1] == 'B' && isSlimp(s, l + 2, r - 1) || isSlump(s, l + 1, r - 1)) && s[r] == 'C';
}

bool isSlurpy(string &s) {
    for (int i = 0; i + 1 < s.size(); i++)
        if (isSlimp(s, 0, i) && isSlump(s, i + 1, s.size() - 1))
            return 1;
    return 0;
}

void solve() {
    string s;
    cin >> s;

    cout << (isSlurpy(s) ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << "SLURPYS OUTPUT\n";
    for (int i = 0; i < n; i++)
        solve();
    cout << "END OF OUTPUT\n";
}