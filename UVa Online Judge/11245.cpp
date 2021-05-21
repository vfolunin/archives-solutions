#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long b(long long n, long long p) {
    if (!n)
        return 1;
    return (p + 1) * b(n / p, p) - (p - n % p);
}

void solve() {
    long long n, p;
    cin >> n >> p;

    cout << b(n - 1, p - 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}