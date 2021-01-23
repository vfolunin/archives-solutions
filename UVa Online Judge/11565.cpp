#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long a, b, c;
    cin >> a >> b >> c;

    for (long long x = -100; x <= 100; x++) {
        for (long long y = x + 1; y <= 100; y++) {
            long long z = a - x - y;
            if (y < z && x * y * z == b && x * x + y * y + z * z == c) {
                cout << x << " " << y << " " << z << "\n";
                return;
            }
        }
    }

    cout << "No solution.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}