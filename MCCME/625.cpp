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

    int emptyWeight, targetWeight, itemCount;
    cin >> emptyWeight >> targetWeight >> itemCount;
    targetWeight -= emptyWeight;

    vector<int> minCost(targetWeight + 1, 1e9);
    vector<int> maxCost(targetWeight + 1, -1e9);
    minCost[0] = maxCost[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int itemCost, itemWeight;
        cin >> itemCost >> itemWeight;

        for (int weight = itemWeight; weight <= targetWeight; weight++) {
            if (minCost[weight - itemWeight] != 1e9) {
                minCost[weight] = min(minCost[weight], minCost[weight - itemWeight] + itemCost);
                maxCost[weight] = max(maxCost[weight], maxCost[weight - itemWeight] + itemCost);
            }
        }
    }

    if (minCost[targetWeight] == 1e9)
        cout << "This is impossible.";
    else
        cout << minCost[targetWeight] << " " << maxCost[targetWeight];
}