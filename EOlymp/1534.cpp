#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

bool solve() {
    int l, r, size;
    if (!(cin >> l >> r >> size))
        return 0;

    vector<int> a(size);
    for (int &value : a)
        cin >> value;

    long long res = 0;
    for (int mask = 1; mask < (1 << size); mask++) {
        int ones = 0;
        long long d = 1;

        for (int bit = 0; bit < size; bit++) {
            if (mask & (1 << bit)) {
                ones++;
                if (d <= 1e9)
                    d = lcm(d, a[bit]);
            }
        }

        long long delta = r / d - (l - 1) / d;
        res += delta * (ones % 2 ? 1 : -1);
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}