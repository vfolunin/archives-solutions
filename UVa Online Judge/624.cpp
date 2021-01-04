#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int maxWeight, itemCount;
    if (!(cin >> maxWeight >> itemCount))
        return 0;

    vector<vector<int>> can(itemCount + 1, vector<int>(maxWeight + 1));
    vector<vector<int>> take(itemCount + 1, vector<int>(maxWeight + 1));
    can[0][0] = 1;

    vector<int> itemWeight(itemCount);
    for (int items = 1; items <= itemCount; items++) {
        cin >> itemWeight[items - 1];
        for (int weight = 0; weight <= maxWeight; weight++) {
            if (can[items - 1][weight])
                can[items][weight] = 1;
            if (weight >= itemWeight[items - 1] && can[items - 1][weight - itemWeight[items - 1]]) {
                can[items][weight] = 1;
                take[items][weight] = 1;
            }
        }
    }

    while (!can[itemCount][maxWeight])
        maxWeight--;

    for (int items = itemCount, weight = maxWeight; items > 0; items--) {
        if (take[items][weight]) {
            cout << itemWeight[items - 1] << " ";
            weight -= itemWeight[items - 1];
        }
    }
    cout << "sum:" << maxWeight << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    
    while (solve());
}