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

    int targetWeight;
    cin >> targetWeight;

    vector<int> minCost(targetWeight + 100, 1e9);
    minCost[0] = 0;

    vector<pair<int, int>> items = { { 1, 4 }, { 10, 30 }, { 50, 125 }, { 100, 200 } };

    for (auto &[itemWeight, itemPrice] : items)
        for (int weight = itemWeight; weight < minCost.size(); weight++)
            minCost[weight] = min(minCost[weight], minCost[weight - itemWeight] + itemPrice);

    cout << *min_element(minCost.begin() + targetWeight, minCost.end());
}