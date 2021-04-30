#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    if (k > n || k < 0)
        return 0;

    static vector<vector<long long>> memo(20, vector<long long>(20, -1));
    if (memo[n][k] != -1)
        return memo[n][k];

    if (k == 0 || k == n)
        return memo[n][k] = 1;

    return memo[n][k] = c(n - 1, k) + c(n - 1, k - 1);
}

long long arranges(int n, int seen) {
    if (seen > n || seen < 0)
        return 0;

    static vector<vector<long long>> memo(20, vector<long long>(20, -1));
    if (memo[n][seen] != -1)
        return memo[n][seen];

    if (seen == n)
        return memo[n][seen] = 1;

    return memo[n][seen] = arranges(n - 1, seen) * (n - 1) + arranges(n - 1, seen - 1);
}

void solve() {
    long long n, seenFromLeft, seenFromRight;
    cin >> n >> seenFromLeft >> seenFromRight;

    long long res = 0;
    for (long long left = 0, right = n - 1; left < n; left++, right--)
        res += c(left + right, right) * arranges(left, seenFromLeft - 1) * arranges(right, seenFromRight - 1);

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