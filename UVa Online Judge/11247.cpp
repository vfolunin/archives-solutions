#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

long long cost(long long kwh) {
    long long res = 0;
    for (auto [amount, tax] : vector<pair<long long, int>>{ {100, 2}, {9900, 3}, {990000, 5} }) {
        long long delta = min(kwh, amount);
        res += delta * tax;
        kwh -= delta;
    }
    res += kwh * 7;
    return res;
}

bool solve() {
    long long start, tax;
    cin >> start >> tax;

    if (!start && !tax)
        return 0;

    long long l = start - 1, r = 1e16 + 1;
    while (l + 1 < r) {
        long long m = l + (r - l) / 2;
        if (m * (100 - tax) < (start - 1) * 100)
            l = m;
        else
            r = m;
    }

    if (l == start - 1 || l == 1e16)
        cout << "Not found\n";
    else
        cout << l << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}