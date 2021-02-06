#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int collatz(long long n) {
    static unordered_map<long long, int> memo;
    if (memo.count(n))
        return memo[n];

    if (n == 1)
        return memo[n] = 0;

    if (n % 2)
        return memo[n] = 1 + collatz(3 * n + 1);
    else
        return memo[n] = 1 + collatz(n / 2);
}

bool solve() {
    int l, r;
    cin >> l >> r;

    if (!l && !r)
        return 0;

    if (l > r)
        swap(l, r);

    int bestI = l, bestLen = (l == 1 ? 3 : collatz(l));
    for (int i = l + 1; i <= r; i++) {
        int len = collatz(i);
        if (len > bestLen) {
            bestI = i;
            bestLen = len;
        }
    }

    cout << "Between " << l << " and " << r << ", " << bestI;
    cout << " generates the longest sequence of " << bestLen << " values.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}