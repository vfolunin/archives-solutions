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

    vector<int> items(itemCount);
    int totalWeight = 0;
    for (int &itemWeight : items) {
        cin >> itemWeight;
        totalWeight += itemWeight;
    }

    if (totalWeight % 2) {
        cout << "NO SOLUTION";
        return 0;
    }

    vector<bool> canMake(totalWeight + 1);
    canMake[0] = 1;
    vector<int> from(totalWeight + 1);

    for (int itemWeight : items) {
        for (int sum = totalWeight; sum >= itemWeight; sum--) {
            if (!canMake[sum] && canMake[sum - itemWeight]) {
                canMake[sum] = true;
                from[sum] = sum - itemWeight;
            }
        }
    }

    int targetWeight = totalWeight / 2;
    while (!canMake[targetWeight])
        targetWeight--;

    multiset<int> itemSet(items.begin(), items.end());

    vector<int> takenItemWeights;
    for (int sum = targetWeight; sum > 0; sum = from[sum]) {
        int itemWeight = sum - from[sum];
        takenItemWeights.push_back(itemWeight);
        itemSet.erase(itemSet.find(itemWeight));
    }

    if (targetWeight != totalWeight / 2) {
        if (!itemSet.empty() && *prev(itemSet.end()) >= totalWeight / 2 - targetWeight) {
            takenItemWeights.push_back(totalWeight / 2 - targetWeight);
        } else {
            cout << "NO SOLUTION";
            return 0;
        }
    }

    for (int weight : takenItemWeights)
        cout << weight << " ";
}