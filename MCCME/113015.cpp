#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int target;
    vector<pair<int, int>> items(3, { 1, 1 });
    cin >> target >> items[1].first >> items[1].second >> items[2].first >> items[2].second;

    vector<int> minCost(1e6, 1e9);
    minCost[0] = 0;

    for (int weight = 1; weight < minCost.size(); weight++)
        for (auto &[itemWeight, itemCost] : items)
            if (weight >= itemWeight && minCost[weight] > minCost[weight - itemWeight] + itemCost)
                minCost[weight] = minCost[weight - itemWeight] + itemCost;

    cout << *min_element(minCost.begin() + target, minCost.end());
}