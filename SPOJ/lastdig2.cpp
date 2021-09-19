#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int binPow(int x, long long p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % 10;
    int r = binPow(x, p / 2);
    return r * r % 10;
}

void solve() {
    string x;
    long long p;
    cin >> x >> p;

    cout << binPow(x.back() - '0', p) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}