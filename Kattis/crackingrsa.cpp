#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int n, e;
    cin >> n >> e;

    int p = 2;
    while (n % p)
        p++;

    int phi = (p - 1) * (n / p - 1);

    long long d = 0;
    while (e * d % phi != 1)
        d++;

    cout << d << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}