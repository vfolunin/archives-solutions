#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> makeMinCost() {
    int itemCount;
    cin >> itemCount;

    vector<int> minCost(1e5 + 1, 1e9);
    minCost[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int item;
        cin >> item;
        for (int sum = minCost.size() - 1; sum >= item; sum--)
            minCost[sum] = min(minCost[sum], minCost[sum - item] + 1);
    }

    return minCost;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    vector<int> minCostA = makeMinCost();
    vector<int> minCostB = makeMinCost();

    int minCostSum = 1e9;
    for (int i = 1; i < minCostA.size(); i++)
        minCostSum = min(minCostSum, minCostA[i] + minCostB[i]);

    if (minCostSum < 1e9)
        cout << minCostSum;
    else
        cout << "impossible";
}