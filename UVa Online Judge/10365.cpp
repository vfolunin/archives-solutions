#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n;
    cin >> n;

    int res = 1e9;
    for (int a = 1; a <= n; a++) {
        for (int b = a; a * b <= n; b++) {
            if (n % (a * b))
                continue;
            int c = n / (a * b);
            res = min(res, 2 * (a * b + a * c + b * c));
        }
    }

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