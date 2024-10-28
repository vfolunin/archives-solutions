#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int read() {
    double value;
    cin >> value;

    return round(value * 100);
}

bool solve() {
    int itemCount;
    cin >> itemCount;
    int weightLimit = read();

    if (!itemCount && !weightLimit)
        return 0;

    vector<int> maxCost(weightLimit + 1, -1e9);
    maxCost[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int itemPrice;
        cin >> itemPrice;
        int itemWeight = read();

        for (int weight = itemWeight; weight < maxCost.size(); weight++)
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