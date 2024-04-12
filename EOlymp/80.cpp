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

    vector<int> price(itemCount);
    for (int &value : price)
        cin >> value;

    sort(price.begin(), price.end());

    vector<int> cost(price.size() + 1);

    for (int items = 1; items <= price.size(); items++) {
        cost[items] = cost[items - 1] + price[items - 1];
        if (items >= 3)
            cost[items] = min(cost[items], cost[items - 3] + price[items - 2] + price[items - 1]);
        if (items >= 4)
            cost[items] = min(cost[items], cost[items - 4] + price[items - 3] + price[items - 2] + price[items - 1]);
    }

    cout << cost.back();
}