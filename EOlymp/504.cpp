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

    int res = 0;
    for (int i = 0; i < s.size(); i++)
        res += s[i] == '-' && (!i || s[i - 1] != 'S') &&
               (i + 1 >= s.size() || s[i + 1] != 'S') &&
               (i + 1 >= s.size() || s[i + 1] != 'B') &&
               (i + 2 >= s.size() || s[i + 2] != 'B');

    cout << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}