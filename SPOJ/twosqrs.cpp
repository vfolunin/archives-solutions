#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    for (long long l = 0, r = 1e6; l <= r; l++) {
        while (l * l + r * r > n)
            r--;
        if (l * l + r * r == n) {
            cout << "Yes\n";
            return;
        }
    }

    cout << "No\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}