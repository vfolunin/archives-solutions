#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int coinCount, targetSum;
    cin >> coinCount >> targetSum;

    vector<int> coins(coinCount);
    for (int &coin : coins)
        cin >> coin;

    vector<int> minCoins(targetSum + 1, 1e9);
    minCoins[0] = 0;

    for (int coin : coins)
        for (int sum = coin; sum <= targetSum; sum++)
            minCoins[sum] = min(minCoins[sum], minCoins[sum - coin] + 1);

    cout << minCoins[targetSum] << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}