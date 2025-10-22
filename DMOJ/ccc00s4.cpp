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

    int targetSum, coinCount;
    cin >> targetSum >> coinCount;

    vector<int> coins(coinCount);
    for (int &coin : coins)
        cin >> coin;

    vector<int> minCoins(targetSum + 1, 1e9);
    minCoins[0] = 0;

    for (int sum = 1; sum < minCoins.size(); sum++)
        for (int coin : coins)
            if (sum >= coin && minCoins[sum] > minCoins[sum - coin] + 1)
                minCoins[sum] = minCoins[sum - coin] + 1;

    if (minCoins[targetSum] != 1e9)
        cout << "Roberta wins in " << minCoins[targetSum] << " strokes.";
    else
        cout << "Roberta acknowledges defeat.";
}