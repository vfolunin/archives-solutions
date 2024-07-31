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

    int weightLimit, itemCount;
    cin >> weightLimit >> itemCount;

    vector<int> maxCost(weightLimit + 1, -1e9);
    maxCost[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight, itemPrice;
        cin >> itemWeight >> itemPrice;

        for (int weight = itemWeight; weight < maxCost.size(); weight++)
            maxCost[weight] = max(maxCost[weight], maxCost[weight - itemWeight] + itemPrice);
    }

    cout << *max_element(maxCost.begin(), maxCost.end());
}