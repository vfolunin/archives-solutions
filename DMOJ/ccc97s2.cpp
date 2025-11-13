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

    for (int a = 1; a <= n; a++) {
        if (n % a)
            continue;
        int b = n / a;

        for (int c = 1; c <= n; c++) {
            if (c == a || c == b || n % c)
                continue;
            int d = n / c;

            if (a + b == c - d) {
                cout << n << " is nasty\n";
                return;
            }
        }
    }

    cout << n << " is not nasty\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}