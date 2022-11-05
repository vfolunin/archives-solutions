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

    vector<vector<int>> maxCost(itemCount + 1, vector<int>(weightLimit + 1, -1));
    maxCost[0][0] = 0;
    vector<vector<int>> takeLast(itemCount + 1, vector<int>(weightLimit + 1));

    for (int i = 1; i <= itemCount; i++) {
        for (int sum = 0; sum <= weightLimit; sum++) {
            maxCost[i][sum] = maxCost[i - 1][sum];
            if (sum >= weight[i - 1] && maxCost[i - 1][sum - weight[i - 1]] != -1 &&
                maxCost[i][sum] < maxCost[i - 1][sum - weight[i - 1]] + cost[i - 1]) {
                maxCost[i][sum] = maxCost[i - 1][sum - weight[i - 1]] + cost[i - 1];
                takeLast[i][sum] = 1;
            }
        }
    }

    int sum = max_element(maxCost.back().begin(), maxCost.back().end()) - maxCost.back().begin();
    for (int i = itemCount; i; i--) {
        if (takeLast[i][sum]) {
            sum -= weight[i - 1];
            cout << i << "\n";
        }
    }
}