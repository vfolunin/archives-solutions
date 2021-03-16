#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int factorialPower(int f, int p) {
    int res = 0;
    while (f) {
        f /= p;
        res += f;
    }
    return res;
}

void solve(int test) {
    int n, f;
    cin >> n >> f;

    int res = 1e9;

    for (int d = 2; d * d <= n; d++) {
        int p = 0;
        while (n % d == 0) {
            p++;
            n /= d;
        }

        if (p)
            res = min(res, factorialPower(f, d) / p);
    }

    if (n != 1)
        res = min(res, factorialPower(f, n));

    cout << "Case " << test << ":\n";
    if (res)
        cout << res << "\n";
    else
        cout << "Impossible to divide\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}