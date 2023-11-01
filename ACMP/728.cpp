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

    int targetWeight, itemCount;
    cin >> targetWeight >> itemCount;

    vector<int> minCost(2e4 + 1, 1e9);
    minCost[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight, itemCost;
        cin >> itemWeight >> itemCost;

        for (int weight = itemWeight; weight < minCost.size(); weight++)
            minCost[weight] = min(minCost[weight], minCost[weight - itemWeight] + itemCost);
    }

    cout << *min_element(minCost.begin() + targetWeight, minCost.end());
}