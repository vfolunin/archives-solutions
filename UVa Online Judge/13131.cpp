#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int a, b;
    cin >> a >> b;

    int sum = 0;
    for (int d = 1; d * d <= a; d++) {
        if (a % d == 0) {
            if (d % b)
                sum += d;
            if (a / d != d && a / d % b)
                sum += a / d;
        }
    }

    cout << sum << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}