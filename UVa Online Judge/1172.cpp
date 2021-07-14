#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int aSize;
    cin >> aSize;

    vector<string> aType(aSize);
    vector<int> aCost(aSize);
    for (int i = 0; i < aSize; i++)
        cin >> aType[i] >> aType[i] >> aCost[i];

    int bSize;
    cin >> bSize;

    vector<string> bType(bSize);
    vector<int> bCost(bSize);
    for (int i = 0; i < bSize; i++)
        cin >> bType[i] >> bType[i] >> bCost[i];

    vector<vector<int>> cost(aSize + 1, vector<int>(bSize + 1));
    vector<vector<int>> count(aSize + 1, vector<int>(bSize + 1));

    for (int ai = 1; ai <= aSize; ai++) {
        for (int bi = 1; bi <= bSize; bi++) {
            if (cost[ai - 1][bi] > cost[ai][bi - 1]) {
                cost[ai][bi] = cost[ai - 1][bi];
                count[ai][bi] = count[ai - 1][bi];
            } else {
                cost[ai][bi] = cost[ai][bi - 1];
                count[ai][bi] = count[ai][bi - 1];
            }
            if (aType[ai - 1] == bType[bi - 1]) {
                int candidateCost = cost[ai - 1][bi - 1] + aCost[ai - 1] + bCost[bi - 1];
                int candidateCount = count[ai - 1][bi - 1] + 1;
                if (cost[ai][bi] < candidateCost || cost[ai][bi] == candidateCost && count[ai][bi] > candidateCount) {
                    cost[ai][bi] = candidateCost;
                    count[ai][bi] = candidateCount;
                }
            }
        }
    }

    cout << cost[aSize][bSize] << " " << count[aSize][bSize] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}