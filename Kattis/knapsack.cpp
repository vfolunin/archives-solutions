#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int capacity, itemCount;
    if (!(cin >> capacity >> itemCount))
        return 0;

    vector<pair<int, int>> items(itemCount);
    for (auto &[itemWeight, itemCost] : items)
        cin >> itemCost >> itemWeight;

    vector<vector<int>> maxCost(itemCount + 1, vector<int>(capacity + 1, -1));
    maxCost[0][0] = 0;
    vector<vector<int>> lastItemIndex(itemCount + 1, vector<int>(capacity + 1, -1));

    for (int i = 1; i <= itemCount; i++) {
        auto &[itemWeight, itemCost] = items[i - 1];
        for (int weight = 0; weight <= capacity; weight++) {
            if (maxCost[i - 1][weight] != -1 && maxCost[i][weight] < maxCost[i - 1][weight]) {
                maxCost[i][weight] = maxCost[i - 1][weight];
            }
            if (weight >= itemWeight && maxCost[i - 1][weight - itemWeight] != -1 &&
                maxCost[i][weight] < maxCost[i - 1][weight - itemWeight] + itemCost) {
                maxCost[i][weight] = maxCost[i - 1][weight - itemWeight] + itemCost;
                lastItemIndex[i][weight] = i - 1;
            }
        }
    }

    vector<int> takenItemIndices;
    int weight = max_element(maxCost[itemCount].begin(), maxCost[itemCount].end()) - maxCost[itemCount].begin();
    while (weight) {
        if (lastItemIndex[itemCount][weight] != -1) {
            takenItemIndices.push_back(lastItemIndex[itemCount][weight]);
            weight -= items[lastItemIndex[itemCount][weight]].first;
        }
        itemCount--;
    }

    cout << takenItemIndices.size() << "\n";
    for (int index : takenItemIndices)
        cout << index << " ";
    cout << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}