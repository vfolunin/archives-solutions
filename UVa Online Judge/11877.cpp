#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

pair<int, int> simulate(int n) {
    int res = 0;
    while (n > 2) {
        res += n / 3;
        n = n / 3 + n % 3;
    }
    return { res, n };
}

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    auto [maxBottles, _] = simulate(n);

    auto [bottles1, residual1] = simulate(n + 1);
    if (residual1 >= 1 && bottles1 > maxBottles)
        maxBottles = bottles1;

    auto [bottles2, residual2] = simulate(n + 2);
    if (residual2 == 2 && bottles2 > maxBottles)
        maxBottles = bottles2;

    cout << maxBottles << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}