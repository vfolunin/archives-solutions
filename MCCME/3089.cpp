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

    int itemCount, weightLimit;
    cin >> itemCount >> weightLimit;

    vector<int> weight(itemCount);
    for (int &w : weight)
        cin >> w;

    vector<int> cost(itemCount);
    for (int &c : cost)
        cin >> c;

    vector<int> maxCost(weightLimit + 1, -1);
    maxCost[0] = 0;

    for (int i = 0; i < itemCount; i++)
        for (int sum = weightLimit; sum >= weight[i]; sum--)
            if (maxCost[sum - weight[i]] != -1)
                maxCost[sum] = max(maxCost[sum], maxCost[sum - weight[i]] + cost[i]);
    
    cout << *max_element(maxCost.begin(), maxCost.end());
}