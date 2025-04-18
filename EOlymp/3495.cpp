#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int knapsackWeight, itemCount;
    cin >> knapsackWeight >> itemCount;

    if (!itemCount)
        return 0;

    vector<int> maxProfit(knapsackWeight + 1, -1e9);
    maxProfit[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight, itemProfit;
        cin >> itemWeight >> itemProfit;

        for (int weight = knapsackWeight; weight >= itemWeight; weight--)
            if (maxProfit[weight - itemWeight] != -1e9)
                maxProfit[weight] = max(maxProfit[weight], maxProfit[weight - itemWeight] + itemProfit);
    }

    int resWeight = max_element(maxProfit.begin(), maxProfit.end()) - maxProfit.begin();

    cout << resWeight << " " << maxProfit[resWeight] << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}