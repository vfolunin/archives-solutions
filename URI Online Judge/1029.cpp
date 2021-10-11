#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepare() {
    vector<long long> fib = { 0, 1 };
    for (int i = 2; i <= 50; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);
    return fib;
}

void solve() {
    int n;
    cin >> n;

    static vector<long long> fib = prepare();

    cout << "fib(" << n << ") = " << 2 * fib[n + 1] - 2 << " calls = " << fib[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}