#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int targetCost;
    cin >> targetCost;

    vector<int> minBills(20001, 1e9);
    minBills[0] = 0;

    int billCount;
    cin >> billCount;

    for (int i = 0; i < billCount; i++) {
        int billCost;
        cin >> billCost;
        for (int cost = 20000; cost >= billCost; cost--)
            if (minBills[cost] > minBills[cost - billCost] + 1)
                minBills[cost] = minBills[cost - billCost] + 1;
    }

    while (minBills[targetCost] == 1e9)
        targetCost++;

    cout << targetCost << " " << minBills[targetCost] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}