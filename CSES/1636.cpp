#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int coinCount, targetSum;
    cin >> coinCount >> targetSum;

    vector<int> coins(coinCount);
    for (int &coin : coins)
        cin >> coin;

    vector<long long> ways(targetSum + 1);
    ways[0] = 1;

    for (int coin : coins)
        for (int sum = coin; sum <= targetSum; sum++)
            ways[sum] = (ways[sum] + ways[sum - coin]) % MOD;

    cout << ways[targetSum];
}