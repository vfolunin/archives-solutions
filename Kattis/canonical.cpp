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

    vector<int> dp(2.1e6, 1e9);
    vector<int> greedy(2.1e6, 1e9);
    dp[0] = greedy[0] = 0;

    for (int sum = 1; sum < dp.size(); sum++) {
        for (int coin : coins)
            if (coin <= sum)
                dp[sum] = min(dp[sum], dp[sum - coin] + 1);

        greedy[sum] = greedy[sum - *--upper_bound(coins.begin(), coins.end(), sum)] + 1;

        if (dp[sum] != greedy[sum]) {
            cout << "non-canonical";
            return 0;
        }
    }

    cout << "canonical";
}