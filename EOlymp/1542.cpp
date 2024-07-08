#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    long long n;
    cin >> n;

    if (!n) {
        cout << "3\n";
        return;
    }

    if (n < 0)
        n = -n;

    for (long long i = sqrt(2 * n); 1; i++) {
        long long sum = i * (i + 1) / 2;
        if (sum >= n && (sum - n) % 2 == 0) {
            cout << i << "\n";
            break;
        }
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}