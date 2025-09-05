#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size, count;
    cin >> size >> count;

    string s(2 * size, '?');
    for (int i = 0; i < count; i++) {
        int index;
        cin >> index;

        s[index - 1] = '(';
    }

    vector<vector<long long>> ways(s.size(), vector<long long>(s.size()));
    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            for (int m = l + 1; m <= r; m++) {
                long long cur = s[m] != '(';
                if (l + 1 <= m - 1)
                    cur *= ways[l + 1][m - 1];
                if (m + 1 <= r)
                    cur *= ways[m + 1][r];
                ways[l][r] += cur;
            }
        }
    }

    cout << ways[0][s.size() - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}