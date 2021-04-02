#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    string s;
    cin >> s;

    if (s == "*")
        return 0;

    vector<vector<int>> f(s.size(), vector<int>(s.size(), 1));

    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = len - 1; r < s.size(); l++, r++) {
            f[l][r] = r - l + 1;
            for (int i = l; i < r; i++)
                f[l][r] = min(f[l][r], f[l][i] + f[i + 1][r]);
            for (int partLen = 1; partLen * 2 <= len; partLen++) {
                int period = 1e9;
                for (int i = l; i < l + partLen; i++) {
                    int curPeriod = 1;
                    while (i + curPeriod * partLen <= r && s[i] == s[i + curPeriod * partLen])
                        curPeriod++;
                    period = min(period, curPeriod);
                }
                if (period > 1) {
                    int candidate = f[l][l + partLen - 1];
                    if (l + partLen * period <= r)
                        candidate += f[l + partLen * period][r];
                    f[l][r] = min(f[l][r], candidate);
                }
            }
        }
    }

    cout << f[0][s.size() - 1] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}