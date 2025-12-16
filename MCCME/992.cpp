#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <tuple>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int shopCount, targetSum;
    cin >> shopCount >> targetSum;
    targetSum *= 2;

    vector<tuple<int, int, int, int>> shopData(shopCount);
    for (auto &[price1, threshold, price2, limit] : shopData)
        cin >> price1 >> threshold >> price2 >> limit;

    vector<vector<int>> minCost(shopCount + 1, vector<int>(targetSum + 1, 2e9));
    vector<vector<pair<int, int>>> from(shopCount + 1, vector<pair<int, int>>(targetSum + 1, { -1, -1 }));
    minCost[0][0] = 0;

    for (int shops = 1; shops <= shopCount; shops++) {
        auto &[price1, threshold, price2, limit] = shopData[shops - 1];
        for (int sum = 0; sum <= targetSum; sum++) {
            for (int count = 0; count <= limit && count <= sum; count++) {
                int candidate = minCost[shops - 1][sum - count] + count * (count < threshold ? price1 : price2);
                if (minCost[shops][sum] > candidate) {
                    minCost[shops][sum] = candidate;
                    from[shops][sum] = { shops - 1, sum - count };
                }
            }
        }
    }

    int shops = shopCount;
    int sum = min_element(minCost.back().begin() + targetSum / 2, minCost.back().end()) - minCost.back().begin();

    if (minCost[shops][sum] == 2e9) {
        cout << -1;
        return 0;
    }

    cout << minCost[shops][sum] << "\n";

    vector<int> count;
    while (shops) {
        auto [prevShops, prevSum] = from[shops][sum];
        count.push_back(sum - prevSum);
        shops = prevShops;
        sum = prevSum;
    }
    reverse(count.begin(), count.end());

    for (int value : count)
        cout << value << " ";
}