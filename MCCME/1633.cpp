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
        cout << pizzaCost;
        return 0;
    }

    vector<int> itemCost(itemCount);
    vector<vector<int>> can(itemCount + 1, vector<int>(deliveryCost));
    can[0][0] = 1;

    for (int items = 1; items <= itemCount; items++) {
        cin >> itemCost[items - 1];
        can[items] = can[items - 1];
        for (int sum = itemCost[items - 1]; sum < deliveryCost; sum++)
            can[items][sum] |= can[items - 1][sum - itemCost[items - 1]];
    }

    int sum = deliveryLimit - pizzaCost;
    while (sum < deliveryCost && !can[itemCount][sum])
        sum++;

    cout << pizzaCost + min(sum, deliveryCost);
}