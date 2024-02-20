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

    int coinCount;
    cin >> coinCount;

    vector<int> coins(coinCount);
    for (int &coin : coins)
        cin >> coin;

    int targetSum;
    cin >> targetSum;

    vector<int> cost(targetSum + 1, 1e9);
    vector<int> from(targetSum + 1, -1);
    cost[0] = 0;

    for (int &coin : coins) {
        for (int sum = coin; sum <= targetSum; sum++) {
            if (cost[sum] > cost[sum - coin] + 1) {
                cost[sum] = cost[sum - coin] + 1;
                from[sum] = sum - coin;
            }
        }
    }

    if (cost[targetSum] != 1e9) {
        vector<int> res;
        for (int sum = targetSum; sum; sum = from[sum])
            res.push_back(sum - from[sum]);

        cout << res.size() << "\n";
        for (int coin : res)
            cout << coin << " ";
    } else {
        cout << -1;
    }
}