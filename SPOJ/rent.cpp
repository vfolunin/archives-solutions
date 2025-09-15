#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Order {
    int l, time, price;

    bool operator < (const Order &that) const {
        return l + time < that.l + that.time;
    }
};

void solve() {
    int orderCount;
    cin >> orderCount;

    vector<Order> orders(orderCount);
    for (auto &[l, time, price] : orders)
        cin >> l >> time >> price;

    sort(orders.begin(), orders.end());
    map<int, long long> maxCost = { { -1, 0 } };

    for (auto &[l, time, price] : orders) {
        if (!maxCost.count(l + time))
            maxCost[l + time] = maxCost.rbegin()->second;
        maxCost[l + time] = max(maxCost[l + time], (--maxCost.lower_bound(l))->second + price);
    }

    cout << maxCost.rbegin()->second << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}