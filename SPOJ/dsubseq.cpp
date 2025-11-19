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

    vector<int> ways(s.size() + 1);
    ways[0] = 1;
    const int MOD = 1e9 + 7;

    vector<int> last(26, -1);
    for (int len = 1; len <= s.size(); len++) {
        ways[len] = ways[len - 1] * 2 % MOD;

        int c = s[len - 1] - 'A';
        if (last[c] != -1)
            ways[len] = (ways[len] - ways[last[c]] + MOD) % MOD;

        last[c] = len - 1;
    }

    cout << ways.back() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}