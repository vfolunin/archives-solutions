#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

unsigned long long c(int n, int m) {
    unsigned long long res = 1;
    for (int num = n - m + 1, den = 1; num <= n; num++) {
        res *= num;
        while (den <= m && res % den == 0)
            res /= den++;
    }
    return res;
}

void solve() {
    int n, m;
    cin >> n >> m;

    cout << c(n - 1, m - 1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}