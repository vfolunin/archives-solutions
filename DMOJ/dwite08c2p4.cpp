#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int weightLimit, itemCount;
    if (!(cin >> weightLimit >> itemCount))
        return 0;

    vector<int> maxCost(weightLimit + 1);
    for (int item = 0; item < itemCount; item++) {
        int itemWeight, itemPrice;
        cin >> itemWeight >> itemPrice;

        for (int weight = weightLimit; weight >= itemWeight; weight--)
            maxCost[weight] = max(maxCost[weight], maxCost[weight - itemWeight] + itemPrice);
    }

    cout << *max_element(maxCost.begin(), maxCost.end()) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}