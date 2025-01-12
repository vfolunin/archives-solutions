#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int getDivisorSum(int n) {
    int res = 0;
    for (long long d = 1; d < n && d * d <= n; d++) {
        if (n % d == 0) {
            res += d;
            if (d != 1 && d * d != n)
                res += n / d;
        }
    }
    return res;
}

void solve() {
    int n;
    cin >> n;

    cout << getDivisorSum(n) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}