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

    vector<int> minCoins(targetSum + 1, 1e9);
    vector<pair<int, int>> from(targetSum + 1, { -1, -1 });
    minCoins[0] = 0;

    for (int i = 0; i < coinCount; i++) {
        int coin;
        cin >> coin;
        for (int sum = coin; sum <= targetSum; sum++) {
            if (minCoins[sum] > minCoins[sum - coin] + 1) {
                minCoins[sum] = minCoins[sum - coin] + 1;
                from[sum] = { sum - coin, coin };
            }
        }
    }

    if (minCoins[targetSum] == 1e9) {
        cout << -1;
        return 0;
    }

    vector<int> path;
    for (int sum = targetSum; sum; sum = from[sum].first)
        path.push_back(from[sum].second);
    sort(path.begin(), path.end());

    cout << path.size() << "\n";
    for (int value : path)
        cout << value << " ";
}