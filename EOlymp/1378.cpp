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

    vector<int> fib = { 1, 2 };
    for (int i = 2; fib.back() <= n; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);

    cout << n << " = ";
    for (int i = fib.size() - 2; i >= 0; i--) {
        if (n >= fib[i]) {
            cout << 1;
            n -= fib[i];
        } else {
            cout << 0;
        }
    }
    cout << " (fib)\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}