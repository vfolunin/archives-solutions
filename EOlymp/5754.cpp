#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Product {
    int cost, deadline;

    bool operator < (const Product &that) const {
        return cost > that.cost;
    }
};

bool solve() {
    int productCount;
    if (!(cin >> productCount))
        return 0;

    vector<Product> products(productCount);
    for (auto &[cost, deadline] : products)
        cin >> cost >> deadline;

    set<int> slots;
    for (int i = 1; i <= productCount; i++)
        slots.insert(i);
    int res = 0;

    sort(products.begin(), products.end());
    for (auto &[cost, deadline] : products) {
        auto it = slots.upper_bound(deadline);
        if (it == slots.begin())
            continue;
        slots.erase(--it);
        res += cost;
    }

    cout << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}