#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
    int maxD, maxLen;
    cin >> maxD >> maxLen;

    long long count[101][10][10][10] = {};
    for (int d = 1; d < maxD; d++)
        count[1][d][d][d] = 1;

    for (int len = 1; len < maxLen; len++) {
        for (int lo = 0; lo < maxD; lo++) {
            for (int hi = lo; hi < maxD; hi++) {
                for (int last = lo; last <= hi; last++) {
                    if (!count[len][lo][hi][last])
                        continue;
                    
                    if (last != 0) {
                        int next = last - 1;
                        long long &nextCount = count[len + 1][min(lo, next)][max(hi, next)][next];
                        nextCount = (nextCount + count[len][lo][hi][last]) % MOD;
                    }

                    if (last != maxD - 1) {
                        int next = last + 1;
                        long long &nextCount = count[len + 1][min(lo, next)][max(hi, next)][next];
                        nextCount = (nextCount + count[len][lo][hi][last]) % MOD;
                    }
                }
            }
        }
    }

    long long res = 0;
    for (int len = 1; len <= maxLen; len++)
        for (int last = 0; last < maxD; last++)
            res = (res + count[len][0][maxD - 1][last]) % MOD;

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