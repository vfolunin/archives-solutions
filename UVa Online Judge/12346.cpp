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

    int gateCount;
    cin >> gateCount;

    vector<long long> rate(gateCount), cost(gateCount);
    for (int i = 0; i < gateCount; i++)
        cin >> rate[i] >> cost[i];

    int testCount;
    cin >> testCount;

    for (int test = 1; test <= testCount; test++) {
        long long volume, time;
        cin >> volume >> time;

        long long minCost = -1;
        for (int mask = 0; mask < (1 << gateCount); mask++) {
            long long totalRate = 0, totalCost = 0;
            for (int bit = 0; bit < gateCount; bit++) {
                if (mask & (1 << bit)) {
                    totalRate += rate[bit];
                    totalCost += cost[bit];
                }
            }
            if (totalRate * time >= volume && (minCost == -1 || minCost > totalCost))
                minCost = totalCost;
        }

        cout << "Case " << test << ": ";
        if (minCost == -1)
            cout << "IMPOSSIBLE\n";
        else
            cout << minCost << "\n";
    }
}