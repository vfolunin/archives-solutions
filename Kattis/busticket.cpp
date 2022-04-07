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

    long long singlePrice, rangePrice, rangeSize;
    int tripCount;
    cin >> singlePrice >> rangePrice >> rangeSize >> tripCount;

    vector<long long> trips(tripCount);
    vector<long long> cost(tripCount);

    for (int i = 0; i < tripCount; i++) {
        cin >> trips[i];

        long long costA = singlePrice + (i ? cost[i - 1] : 0);
        long long costB = rangePrice;
        auto it = upper_bound(trips.begin(), trips.begin() + i, trips[i] - rangeSize);
        if (it != trips.begin())
            costB += cost[prev(it) - trips.begin()];

        cost[i] = min(costA, costB);
    }

    cout << cost.back();
}