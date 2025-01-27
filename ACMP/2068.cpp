#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int rec(int n) {
    static vector<int> memo(4e3, -1);
    int &res = memo[n];
    if (res != -1)
        return res;

    const int MOD = 998244353;

    if (n < 3) {
        return res = n % MOD;
    } else if (n % 2) {
        return res = (rec(n - 1) + rec(n - 2) + 1) % MOD;
    } else {
        res = 0;
        for (int i = 1; i < n; i++)
            res = (res + rec(i)) % MOD;
        return res;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    cout << rec(n);
}