#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int binPow(int x, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x % 1000;
    int r = binPow(x, p / 2);
    return r * r % 1000;
}

void solve() {
    int n, k;
    cin >> n >> k;

    double p = k * log10(n);
    p -= floor(p);

    string a = to_string(pow(10, p) * 100).substr(0, 3);
    int b = binPow(n % 1000, k);

    cout << a << "..." << setw(3) << setfill('0') << b << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}