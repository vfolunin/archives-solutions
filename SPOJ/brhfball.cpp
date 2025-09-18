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

    int targetSum;
    cin >> targetSum;

    const int MOD = 1e4;
    vector<int> ways(targetSum + 1);
    ways[0] = 1;

    for (int sum = 0; sum < ways.size(); sum++)
        for (int value : { 2, 3, 6, 7, 8 })
            if (sum >= value)
                ways[sum] = (ways[sum] + ways[sum - value]) % MOD;

    cout << ways[targetSum];
}