#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long grundy(long long n) {
    return n % 2 ? grundy(n / 2) : n / 2;
}

void solve() {
    int pileCount;
    cin >> pileCount;

    long long xorSum = 0;
    for (int i = 0; i < pileCount; i++) {
        long long pile;
        cin >> pile;
        xorSum ^= grundy(pile);
    }

    cout << (xorSum ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}