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

    int pizzaCost, deliveryCost, deliveryLimit, itemCount;
    cin >> pizzaCost >> deliveryCost >> deliveryLimit >> itemCount;
    deliveryLimit++;

    if (pizzaCost >= deliveryLimit) {
        cout << pizzaCost << "\n0";
        return 0;
    }

    vector<int> itemCost(itemCount);
    vector<vector<int>> can(itemCount + 1, vector<int>(deliveryCost));
    can[0][0] = 1;
    vector<vector<int>> take(itemCount + 1, vector<int>(deliveryCost));

    for (int items = 1; items <= itemCount; items++) {
        cin >> itemCost[items - 1];
        can[items] = can[items - 1];
        for (int sum = itemCost[items - 1]; sum < deliveryCost; sum++) {
            if (can[items - 1][sum - itemCost[items - 1]]) {
                can[items][sum] = 1;
                take[items][sum] = 1;
            }
        }
    }

    int sum = deliveryLimit - pizzaCost;
    while (sum < deliveryCost && !can[itemCount][sum])
        sum++;

    if (sum >= deliveryCost) {
        cout << pizzaCost + deliveryCost << "\n-1";
        return 0;
    }

    cout << pizzaCost + sum << "\n";

    vector<int> takenItems;
    for (int items = itemCount; sum; items--) {
        if (take[items][sum]) {
            sum -= itemCost[items - 1];
            takenItems.push_back(items - 1);
        }
    }
    reverse(takenItems.begin(), takenItems.end());

    cout << takenItems.size() << " ";
    for (int index : takenItems)
        cout << index + 1 << " ";
}