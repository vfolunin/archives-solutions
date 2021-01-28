#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int money, itemCount;
    if (!(cin >> money >> itemCount))
        return 0;

    vector<int> maxProfit(money + 201, -1);
    maxProfit[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int price, profit;
        cin >> price >> profit;

        for (int i = money + 200; i >= price; i--)
            if (maxProfit[i - price] != -1 && maxProfit[i] < maxProfit[i - price] + profit)
                maxProfit[i] = maxProfit[i - price] + profit;
    }

    int res = *max_element(maxProfit.begin(), maxProfit.begin() + money + 1);
    if (money > 1800)
        res = max(res, *max_element(maxProfit.begin() + 2001, maxProfit.end()));

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}