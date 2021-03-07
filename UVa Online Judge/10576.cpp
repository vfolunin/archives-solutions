#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long a, b;
    if (!(cin >> a >> b))
        return 0;

    long long res = -1e18;

    for (int mask = 0; mask < (1 << 12); mask++) {
        vector<long long> profit(12);
        for (int bit = 0; bit < 12; bit++) {
            if (mask & (1 << bit))
                profit[bit] = a;
            else
                profit[bit] = -b;
            if (bit)
                profit[bit] += profit[bit - 1];
        }

        bool ok = 1;
        for (int bit = 4; ok && bit < 12; bit++)
            ok &= profit[bit] - (bit - 5 + 1 ? profit[bit - 5] : 0) < 0;

        if (ok)
            res = max(res, profit.back());
    }

    if (res >= 0)
        cout << res << "\n";
    else
        cout << "Deficit\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}