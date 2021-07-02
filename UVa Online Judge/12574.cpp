#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

void solve() {
    int listCount;
    cin >> listCount;

    long long sum = 0, res = 1;
    for (int i = 0; i < listCount; i++) {
        long long listSize;
        cin >> listSize;

        sum += listSize;
        res = (res * (listSize + 1)) % MOD;
    }

    res = ((res - sum - 1) % MOD + MOD) % MOD;

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