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

    vector<int> can(1e5 + 1);
    can[0] = true;

    for (int coin : coins)
        for (int sum = 1e5; sum >= coin; sum--)
            can[sum] |= can[sum - coin];

    vector<int> res;
    for (int sum = 1; sum <= 1e5; sum++)
        if (can[sum])
            res.push_back(sum);

    cout << res.size() << "\n";
    for (int sum : res)
        cout << sum << " ";
}