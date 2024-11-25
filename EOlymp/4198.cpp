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

    int itemCount;
    cin >> itemCount;

    vector<int> itemWeights(itemCount);
    int totalWeight = 0;
    for (int &itemWeight : itemWeights) {
        cin >> itemWeight;
        totalWeight += itemWeight;
    }

    vector<int> can(totalWeight + 1);
    can[0] = 1;

    for (int itemWeight : itemWeights)
        for (int weight = can.size() - 1; weight >= itemWeight; weight--)
            can[weight] |= can[weight - itemWeight];

    int res = totalWeight / 2;
    while (!can[res])
        res--;

    cout << totalWeight - res;
}