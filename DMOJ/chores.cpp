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

    int pairCount;
    cin >> pairCount;

    vector<pair<long long, long long>> pairs(pairCount);
    for (auto &[value, count] : pairs)
        cin >> value >> count;

    sort(pairs.begin(), pairs.end());

    long long time = 0, res = 0;
    const long long MOD = 1e9 + 7;

    for (auto &[value, count] : pairs) {
        res = (res + time * count % MOD + (count * (count + 1) / 2) % MOD * value % MOD) % MOD;
        time = (time + value * count) % MOD;
    }

    cout << res;
}