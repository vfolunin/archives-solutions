#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    vector<int> value(4);
    for (int &v : value)
        cin >> v;

    vector<long long> ways(1e5 + 1);
    ways[0] = 1;
    for (int v : value)
        for (int sum = v; sum < ways.size(); sum++)
            ways[sum] += ways[sum - v];

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        vector<int> limit(4);
        for (int &l : limit)
            cin >> l;

        int sum;
        cin >> sum;

        long long res = 0;

        for (int mask = 0; mask < 16; mask++) {
            long long delta = 0;
            int ones = 0;

            for (int bit = 0; bit < 4; bit++) {
                if (mask & (1 << bit)) {
                    delta += value[bit] * (limit[bit] + 1);
                    ones++;
                }
            }

            if (sum >= delta) {
                if (ones % 2)
                    res -= ways[sum - delta];
                else
                    res += ways[sum - delta];
            }
        }

        cout << res << "\n";
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}