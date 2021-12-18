#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> prepare() {
    vector<int> fib = { 1, 2 };
    for (int i = 2; i < 25; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> fib = prepare();

    int res = 0;
    for (int i = fib.size() - 1; i > 0; i--) {
        if (n >= fib[i]) {
            n -= fib[i];
            res += fib[i - 1];
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