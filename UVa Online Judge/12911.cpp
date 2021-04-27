#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    long long targetSum;
    if (!(cin >> n >> targetSum))
        return 0;

    vector<long long> v(n);
    for (long long &x : v)
        cin >> x;

    int aSize = n / 2, bSize = n - aSize;
    map<long long, long long> aSums, bSums;

    for (int mask = 0; mask < (1 << aSize); mask++) {
        long long sum = 0;
        for (int bit = 0; bit < aSize; bit++)
            if (mask & (1 << bit))
                sum += v[bit];
        aSums[sum]++;
    }

    for (int mask = 0; mask < (1 << bSize); mask++) {
        long long sum = 0;
        for (int bit = 0; bit < bSize; bit++)
            if (mask & (1 << bit))
                sum += v[aSize + bit];
        bSums[sum]++;
    }

    long long res = 0;
    for (auto &[aSum, _] : aSums)
        if (bSums.count(targetSum - aSum))
            res += aSums[aSum] * bSums[targetSum - aSum];
    
    cout << res - !targetSum << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}