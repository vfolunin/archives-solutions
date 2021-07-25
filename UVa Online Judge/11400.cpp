#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Category {
    int voltage, sourceCost, lampCost, lampCount;

    bool operator < (const Category &that) const {
        return voltage < that.voltage;
    }
};

int rec(vector<Category> &categories, int categoryCount, vector<int> &memo) {
    int &res = memo[categoryCount];
    if (res != -1)
        return res;

    auto [_, sourceCost, lampCost, lampCount] = categories[categoryCount - 1];
    res = rec(categories, categoryCount - 1, memo) + sourceCost + lampCost * lampCount;

    for (int i = categoryCount - 1; i > 0; i--) {
        lampCount += categories[i - 1].lampCount;
        res = min(res, rec(categories, i - 1, memo) + sourceCost + lampCost * lampCount);
    }

    return res;
}

bool solve() {
    int categoryCount;
    cin >> categoryCount;

    if (!categoryCount)
        return 0;
    
    vector<Category> categories(categoryCount);
    for (auto &[voltage, sourceCost, lampCost, lampCount] : categories)
        cin >> voltage >> sourceCost >> lampCost >> lampCount;

    sort(categories.begin(), categories.end());

    vector<int> memo(categoryCount + 1, -1);
    memo[0] = 0;

    cout << rec(categories, categoryCount, memo) << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}