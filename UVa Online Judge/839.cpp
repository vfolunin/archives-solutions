#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<bool, long long> rec() {
    long long w1, d1, w2, d2;
    cin >> w1 >> d1 >> w2 >> d2;
    bool balanced = 1;

    if (!w1) {
        auto [b, w] = rec();
        balanced &= b;
        w1 = w;
    }

    if (!w2) {
        auto [b, w] = rec();
        balanced &= b;
        w2 = w;
    }

    return { balanced && w1 * d1 == w2 * d2, w1 + w2 };
}

void solve(int test) {
    if (test)
        cout << "\n";
    cout << (rec().first ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}