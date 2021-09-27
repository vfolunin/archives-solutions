#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long rec(int len, int last) {
    static vector<vector<long long>> memo(65, vector<long long>(10, -1));
    long long &res = memo[len][last];
    if (res != -1)
        return res;

    if (len == 1)
        return res = 1;

    res = 0;
    for (int prev = 0; prev <= last; prev++)
        res += rec(len - 1, prev);
    return res;
}

void solve() {
    int test, len;
    cin >> test >> len;

    long long res = 0;
    for (int last = 0; last < 10; last++)
        res += rec(len, last);

    cout << test << " " << res << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}