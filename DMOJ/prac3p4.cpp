#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int targetSum, coinCount;
    cin >> targetSum >> coinCount;

    if (!targetSum && !coinCount)
        return 0;

    vector<int> coins(coinCount);
    for (int &coin : coins)
        cin >> coin;

    vector<int> minCoins(targetSum + 1, 1e9);
    minCoins[0] = 0;

    for (int sum = 1; sum < minCoins.size(); sum++)
        for (int coin : coins)
            if (sum >= coin && minCoins[sum] > minCoins[sum - coin] + 1)
                minCoins[sum] = minCoins[sum - coin] + 1;

    cout << (minCoins[targetSum] != 1e9 ? minCoins[targetSum] : -1) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}