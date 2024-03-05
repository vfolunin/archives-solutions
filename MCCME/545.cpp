#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> knapsack(vector<pair<int, int>> &items) {
    vector<int> can(5001);
    can[0] = 1;

    for (auto &[itemWeight, itemIndex] : items)
        for (int weight = can.size() - 1; weight >= itemWeight; weight--)
            can[weight] |= can[weight - itemWeight];

    return can;
}

void knapsackCertificate(vector<pair<int, int>> &items, int totalWeight) {
    vector<int> lastIndex(totalWeight + 1, -1);
    lastIndex[0] = -2;

    for (int i = 0; i < items.size(); i++) {
        int itemWeight = items[i].first;
        for (int weight = lastIndex.size() - 1; weight >= itemWeight; weight--)
            if (lastIndex[weight] == -1 && lastIndex[weight - itemWeight] != -1)
                lastIndex[weight] = i;
    }

    while (totalWeight) {
        cout << items[lastIndex[totalWeight]].second << " ";
        totalWeight -= items[lastIndex[totalWeight]].first;
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int itemCount, colorCount;
    cin >> itemCount >> colorCount;

    vector<vector<pair<int, int>>> items(colorCount);
    int totalWeight = 0;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight, itemColor;
        cin >> itemWeight >> itemColor;

        items[itemColor - 1].push_back({ itemWeight, i + 1 });
        if (itemColor == 1)
            totalWeight += itemWeight;
    }

    vector<int> can(totalWeight + 1, 1);
    for (vector<pair<int, int>> &colorItems : items) {
        vector<int> curCan = knapsack(colorItems);
        for (int weight = 0; weight <= totalWeight; weight++)
            can[weight] &= curCan[weight];
    }

    int resWeight = 1;
    while (resWeight < totalWeight && !can[resWeight])
        resWeight++;

    if (resWeight == totalWeight) {
        cout << "NO";
        return 0;
    }

    cout << "YES\n";
    for (vector<pair<int, int>> &colorItems : items)
        knapsackCertificate(colorItems, resWeight);
}