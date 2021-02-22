#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getFib() {
    vector<int> fib = { 1, 2 };
    while (fib.back() <= 1e8)
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    return fib;
}

void solve() {
    int n;
    cin >> n;

    cout << n << " = ";

    vector<int> fib = getFib();
    for (auto it = --upper_bound(fib.begin(), fib.end(), n); 1; it--) {
        if (*it <= n) {
            cout << 1;
            n -= *it;
        } else {
            cout << 0;
        }
        if (it == fib.begin())
            break;
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