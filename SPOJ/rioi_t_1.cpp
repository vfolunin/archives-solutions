#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long c(int n, int k) {
    static vector<vector<long long>> memo(30, vector<long long>(30, -1));
    long long &res = memo[n][k];
    if (res != -1)
        return res;

    if (k == 0 || k == n)
        return res = 1;

    return res = (c(n - 1, k) + c(n - 1, k - 1));
}

void solve() {
    int n, k;
    cin >> n >> k;

    cout << (k <= n ? c(n, k) : 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}