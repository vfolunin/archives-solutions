#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    string s;
    cin >> s;

    vector<vector<long long>> sum(s.size(), vector<long long>(s.size(), -1e18));

    for (int i = 0; i < s.size(); i++)
        sum[i][i] = s[i] - '0';

    long long limit = (1LL << 31) - 1;
    for (int len = 2; len <= s.size(); len++) {
        for (int l = 0, r = l + len - 1; r < s.size(); l++, r++) {
            if (s[l] != '0' && r - l + 1 <= 10) {
                long long num = 0;
                for (int i = l; i <= r; i++)
                    num = num * 10 + s[i] - '0';
                if (num <= limit) {
                    sum[l][r] = num;
                    continue;
                }
            }

            for (int m = l; m < r; m++)
                sum[l][r] = max(sum[l][r], sum[l][m] + sum[m + 1][r]);
        }
    }

    cout << sum[0][s.size() - 1] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}