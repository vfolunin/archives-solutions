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

    vector<int> l(26), r(26);
    for (char c : s)
        r[c - 'a']++;

    for (int i = 0; i < s.size(); i++) {
        r[s[i] - 'a']--;
        if (i && i + 1 < s.size() && (l[s[i] - 'a'] || r[s[i] - 'a'])) {
            cout << "YES\n";
            return;
        }
        l[s[i] - 'a']++;
    }

    cout << "NO\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}