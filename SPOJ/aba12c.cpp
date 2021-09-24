#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int targetSum;
    cin >> targetSum >> targetSum;

    vector<int> minCost(targetSum + 1, 1e9);
    minCost[0] = 0;

    for (int size = 1; size <= targetSum; size++) {
        int cost;
        cin >> cost;

        if (cost != -1)
            for (int sum = size; sum <= targetSum; sum++)
                minCost[sum] = min(minCost[sum], minCost[sum - size] + cost);
    }

    cout << (minCost.back() != 1e9 ? minCost.back() : -1) << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}