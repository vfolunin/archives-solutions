#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

struct Order {
    int amount, deadline;

    bool operator < (const Order &that) const {
        return deadline < that.deadline;
    }
};

void solve(int test) {
    int orderCount;
    cin >> orderCount;

    vector<Order> orders(orderCount);
    for (auto &[amount, deadline] : orders)
        cin >> amount >> deadline;

    sort(orders.begin(), orders.end());
    multiset<int> takenAmounts;
    int last = 0;

    for (auto &[amount, deadline] : orders) {
        if (last + amount <= deadline) {
            last += amount;
            takenAmounts.insert(amount);
        } else if (!takenAmounts.empty() && amount < *--takenAmounts.end()) {
            last -= *--takenAmounts.end();
            takenAmounts.erase(--takenAmounts.end());
            last += amount;
            takenAmounts.insert(amount);
        }
    }

    if (test)
        cout << "\n";
    cout << takenAmounts.size() << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve(i);
}