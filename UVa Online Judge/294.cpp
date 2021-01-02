#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int divisorCount(int n) {
    int d = 0;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            d++;
            if (i * i != n)
                d++;
        }
    }
    return d;
}

void solve() {
    int l, r;
    cin >> l >> r;

    int bestI = l, bestD = divisorCount(l);
    for (int i = l + 1; i <= r; i++) {
        int d = divisorCount(i);
        if (d > bestD) {
            bestI = i;
            bestD = d;
        }
    }

    cout << "Between " << l << " and " << r << ", ";
    cout << bestI << " has a maximum of " << bestD << " divisors.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}