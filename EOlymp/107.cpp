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

    int targetSum;
    cin >> targetSum;

    vector<int> cost(2000, 1e9);
    cost[0] = 0;

    vector<pair<int, int>> items = { {100, 100}, {20, 30}, {1, 2} };
    for (auto &[weight, price] : items)
        for (int sum = weight; sum < cost.size(); sum++)
            cost[sum] = min(cost[sum], cost[sum - weight] + price);

    cout << *min_element(cost.begin() + targetSum, cost.end());
}