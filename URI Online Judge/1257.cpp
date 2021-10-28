#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int res = 0;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;

        for (int j = 0; j < s.size(); j++)
            res += s[j] - 'A' + i + j;
    }

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