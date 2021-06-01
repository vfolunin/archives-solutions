#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<long long> getFib() {
    vector<long long> fib = { 1, 1 };
    for (int i = 2; fib.back() < 3e9; i++)
        fib.push_back(fib[i - 2] + fib[i - 1]);
    return fib;
}

bool getBit(long long n, long long i) {
    static vector<long long> fib = getFib();
    if (n <= 1)
        return n;
    if (i < fib[n - 2])
        return getBit(n - 2, i);
    else
        return getBit(n - 1, i - fib[n - 2]);
}

void solve() {
    long long n, l, r;
    cin >> n >> l >> r;

    static vector<long long> fib = getFib();
    if (n >= fib.size())
        n = (n % 2 ? fib.size() - 1 : fib.size() - 2);

    for (long long i = l; i <= r; i++)
        cout << getBit(n, i);
    cout << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}