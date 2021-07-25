#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e6 + 7;

long long c(long long n, long long m) {
    if (m < 0 || n < m)
        return 0;

    static vector<vector<long long>> memo(501, vector<long long>(501, -1));
    long long &res = memo[n][m];
    if (res != -1)
        return res;

    if (m == 0 || m == n)
        return res = 1;

    return res = c(n - 1, m) + c(n - 1, m - 1) % MOD;
}

void solve(int test) {
    int rows, cols, k;
    cin >> rows >> cols >> k;

    long long res = 0;

    for (int n = 0; n <= cols - 2; n++) {
        long long kn = c(cols - 2, n);
        if (!kn)
            continue;

        for (int e = 0; e <= rows - 2; e++) {
            long long ke = c(rows - 2, e);
            if (!ke)
                continue;

            for (int s = 0; s <= cols - 2; s++) {
                long long ks = c(cols - 2, s);
                if (!ks)
                    continue;

                for (int w = 0; w <= rows - 2; w++) {
                    long long kw = c(rows - 2, w);
                    if (!kw)
                        continue;

                    for (int ne = 0; ne <= 1; ne++) {
                        for (int se = 0; se <= 1; se++) {
                            for (int sw = 0; sw <= 1; sw++) {
                                for (int nw = 0; nw <= 1; nw++) {

                                    long long m = k - (n + ne + e + se + s + sw + w + nw);
                                    long long km = c((rows - 2) * (cols - 2), m);
                                    if (!km)
                                        continue;

                                    if (nw + n + ne && ne + e + se && se + s + sw && sw + w + nw) {
                                        long long cur = 1;
                                        cur = cur * kn % MOD;
                                        cur = cur * ke % MOD;
                                        cur = cur * ks % MOD;
                                        cur = cur * kw % MOD;
                                        cur = cur * km % MOD;
                                        res = (res + cur) % MOD;
                                    }

                                }
                            }
                        }
                    }

                }

            }

        }

    }

    cout << "Case " << test << ": " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}