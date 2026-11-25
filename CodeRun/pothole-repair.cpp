#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <numeric>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size, segmentCount;
    long long limit;
    cin >> size >> segmentCount >> limit;

    vector<long long> holeCount(size);
    for (long long &value : holeCount)
        cin >> value;

    vector<long long> holePrice(size);
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        holePrice[l]++;
        if (r < size)
            holePrice[r]--;
    }
    partial_sum(holePrice.begin(), holePrice.end(), holePrice.begin());

    multiset<pair<long long, long long>> q;
    long long res = 0;
    for (int i = 0; i < size; i++) {
        q.insert({ holePrice[i], holeCount[i] });
        res += holeCount[i] * holePrice[i];
    }

    while (!q.empty() && limit) {
        auto [price, count] = *prev(q.end());
        q.erase(prev(q.end()));
        long long delta = min(count, limit);
        limit -= delta;
        res -= delta * price;
    }

    cout << res;
}