#include <iostream>
#include <iomanip>
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

    vector<int> nominals(coinCount);
    for (int &x : nominals)
        cin >> x;

    vector<long long> ways(targetSum + 1);
    ways[0] = 1;

    for (int sum = 1; sum <= targetSum; sum++)
        for (int nominal : nominals)
            if (nominal <= sum)
                ways[sum] = (ways[sum] + ways[sum - nominal]) % MOD;
    
    cout << ways[targetSum];
}