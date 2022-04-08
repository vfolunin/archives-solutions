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

    int concertTime, itemCount;
    cin >> concertTime >> itemCount;

    vector<int> itemWeights(itemCount);
    int totalWeight = 0;
    for (auto &itemWeight : itemWeights) {
        cin >> itemWeight;
        totalWeight += itemWeight;
    }

    vector<vector<int>> can(itemCount + 1, vector<int>(totalWeight + 1));
    can[0][0] = 1;
    vector<vector<int>> lastItemIndex(itemCount + 1, vector<int>(totalWeight + 1, -1));

    for (int i = 1; i <= itemCount; i++) {
        int itemWeight = itemWeights[i - 1];
        for (int weight = 0; weight <= totalWeight; weight++) {
            if (can[i - 1][weight]) {
                can[i][weight] = 1;
            }
            if (weight >= itemWeight && can[i - 1][weight - itemWeight]) {
                can[i][weight] = 1;
                lastItemIndex[i][weight] = i - 1;
            }
        }
    }

    int groupAWeight = totalWeight / 2;
    while (!can[itemCount][groupAWeight])
        groupAWeight--;

    vector<int> groupA;
    for (int itemCount = can.size() - 1; groupAWeight; itemCount--) {
        if (lastItemIndex[itemCount][groupAWeight] != -1) {
            groupA.push_back(lastItemIndex[itemCount][groupAWeight]);
            groupAWeight -= itemWeights[lastItemIndex[itemCount][groupAWeight]];
        }
    }
    reverse(groupA.begin(), groupA.end());

    int groupATimer = 0, groupBTimer = 0;
    for (int i = 0; i < itemCount; i++) {
        if (binary_search(groupA.begin(), groupA.end(), i)) {
            cout << groupATimer << " ";
            groupATimer += itemWeights[i];
        } else {
            cout << groupBTimer << " ";
            groupBTimer += itemWeights[i];
        }
    }
}