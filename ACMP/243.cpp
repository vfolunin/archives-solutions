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
    minCost[0][0] = 0;

    for (int shops = 1; shops <= shopCount; shops++) {
        auto &[price1, threshold, price2, limit] = shopData[shops - 1];
        for (int sum = 0; sum <= targetSum; sum++)
            for (int count = 0; count <= limit && count <= sum; count++)
                minCost[shops][sum] = min(minCost[shops][sum], minCost[shops - 1][sum - count] + count * (count < threshold ? price1 : price2));
    }

    int res = *min_element(minCost.back().begin() + targetSum / 2, minCost.back().end());

    cout << (res != 2e9 ? res : -1);
}