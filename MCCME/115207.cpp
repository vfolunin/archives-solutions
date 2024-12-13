#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> prepareFib() {
    vector<long long> fib = { 2, 3 };
    for (int i = 2; fib.back() <= 1e18; i++)
        fib.push_back(fib[i - 1] + fib[i - 2]);
    return fib;
}

int rec(long long n, int from) {
    if (n == 1)
        return 1;

    static vector<long long> fib = prepareFib();
    if (from == fib.size() || n < fib[from])
        return 0;

    long long res = rec(n, from + 1);
    if (n % fib[from] == 0)
        res += rec(n / fib[from], from);
    return res;
}

void solve() {
    long long n;
    cin >> n;

    cout << rec(n, 0) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}