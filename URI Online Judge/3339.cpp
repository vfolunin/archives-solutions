#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int squaresTo(int n) {
    return sqrt(n) + 1;
}

int squaresInRange(int l, int r) {
    return squaresTo(r) - (l ? squaresTo(l - 1) : 0);
}

void solve() {
    int l, r;
    cin >> l >> r;

    cout << squaresInRange(l, r) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}