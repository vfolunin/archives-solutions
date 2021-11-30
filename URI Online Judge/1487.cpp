#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve(int test) {
    int itemCount, maxWeight;
    cin >> itemCount >> maxWeight;

    if (!itemCount && !maxWeight)
        return 0;

    vector<int> maxCost(maxWeight + 1);
    for (int i = 0; i < itemCount; i++) {
        int itemWeight, itemCost;
        cin >> itemWeight >> itemCost;
        for (int w = itemWeight; w <= maxWeight; w++)
            maxCost[w] = max(maxCost[w], maxCost[w - itemWeight] + itemCost);
    }

    cout << "Instancia " << test << "\n";
    cout << *max_element(maxCost.begin(), maxCost.end()) << "\n\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    for (int test = 1; solve(test); test++);
}