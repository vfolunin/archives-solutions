#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int appleCount;
    cin >> appleCount;

    vector<long long> weight(appleCount);
    long long totalWeight = 0;
    for (long long &w : weight) {
        cin >> w;
        totalWeight += w;
    }

    long long res = totalWeight;
    for (int mask = 0; mask < (1 << appleCount); mask++) {
        long long maskWeight = 0;
        for (int bit = 0; bit < appleCount; bit++)
            if (mask & (1 << bit))
                maskWeight += weight[bit];
        res = min(res, abs(totalWeight - 2 * maskWeight));
    }

    cout << res;
}