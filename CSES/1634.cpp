#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int coinCount, targetSum;
    cin >> coinCount >> targetSum;

    vector<int> nominals(coinCount);
    for (int &x : nominals)
        cin >> x;

    vector<int> minCoins(targetSum + 1, 1e9);
    minCoins[0] = 0;

    for (int sum = 1; sum <= targetSum; sum++)
        for (int nominal : nominals)
            if (nominal <= sum)
                minCoins[sum] = min(minCoins[sum], minCoins[sum - nominal] + 1);
    
    cout << (minCoins[targetSum] != 1e9 ? minCoins[targetSum] : -1);
}