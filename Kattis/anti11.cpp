#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

vector<int> prepare() {
    vector<int> fib = { 1, 2 };
    for (int i = 2; i <= 1e4; i++)
        fib.push_back((fib[i - 1] + fib[i - 2]) % MOD);
    return fib;
}

void solve() {
    int n;
    cin >> n;

    static vector<int> fib = prepare();

    cout << fib[n] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}