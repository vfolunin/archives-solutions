#include <iostream>
#include <algorithm>
#include <vector>
#include <array>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int targetSum;
    cin >> targetSum;

    static array<array<long long, 4>, (int)1e6 + 1> ways;
    ways[0][0] = 1;

    vector<int> coins = { 1, 2, 5, 10 };
    for (int sum = 1; sum <= targetSum; sum++)
        for (int last = 0; last < coins.size() && sum >= coins[last]; last++)
            for (int prev = 0; prev <= last; prev++)
                ways[sum][last] += ways[sum - coins[last]][prev];

    long long res = 0;
    for (int last = 0; last < coins.size(); last++)
        res += ways[targetSum][last];

    cout << res;
}