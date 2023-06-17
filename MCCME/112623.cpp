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

    vector<long long> ways(targetSum + 1);
    ways[0] = 1;

    for (int i = 0; i < coinCount; i++) {
        int coin;
        cin >> coin;

        for (int sum = coin; sum <= targetSum; sum++)
            ways[sum] += ways[sum - coin];
    }

    cout << ways[targetSum];
}