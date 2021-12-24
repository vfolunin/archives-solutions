#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int itemCount;
    cin >> itemCount;

    if (!itemCount)
        return 0;

    vector<pair<int, int>> items(itemCount);
    for (auto &[itemCost, itemWeight] : items)
        cin >> itemCost >> itemWeight;

    int maxWeight;
    cin >> maxWeight;
    
    vector<int> maxCost(maxWeight + 1);
    for (auto &[itemCost, itemWeight] : items)
        for (int w = maxWeight; w >= itemWeight; w--)
            maxCost[w] = max(maxCost[w], maxCost[w - itemWeight] + itemCost);

    cout << *max_element(maxCost.begin(), maxCost.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}