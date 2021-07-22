#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int safeCount, keeperCount;
    cin >> safeCount >> keeperCount;

    if (!safeCount && !keeperCount)
        return 0;

    vector<int> keeperCost(keeperCount);
    for (int &cost : keeperCost)
        cin >> cost;

    int l = 0, r = 1e9;
    while (l + 1 < r) {
        int m = l + (r - l) / 2;

        long long k = 0;
        for (int cost : keeperCost)
            k += cost / m;

        if (k >= safeCount)
            l = m;
        else
            r = m;
    }

    if (!l) {
        cout << "0 0\n";
        return 1;
    }

    vector<int> keeperValue(keeperCount);
    for (int i = 0; i < keeperCount; i++)
        keeperValue[i] = keeperCost[i] / l;

    vector<vector<int>> minCost(keeperCount + 1, vector<int>(safeCount + 1, 1e9));
    minCost[0][0] = 0;

    for (int keepers = 1; keepers <= keeperCount; keepers++) {
        for (int safes = 0; safes <= safeCount; safes++) {
            minCost[keepers][safes] = minCost[keepers - 1][safes];
            int prevSafes = max(0, safes - keeperValue[keepers - 1]);
            if (minCost[keepers][safes] > minCost[keepers - 1][prevSafes] + keeperCost[keepers - 1])
                minCost[keepers][safes] = minCost[keepers - 1][prevSafes] + keeperCost[keepers - 1];
        }
    }

    cout << l << " " << minCost[keeperCount][safeCount] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}