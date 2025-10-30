#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int id, a, b;
    if (!(cin >> id >> a >> b))
        return 0;

    int amount = b - a + (a < b ? 0 : 10000);
    amount = max(amount - 10, 0);

    vector<int> limit = { 20, 55, 85, (int)1e9 };
    vector<double> price = { .2373, .2271, .2178, .2085 };

    double cost = 6.59;
    for (int i = 0; i < limit.size(); i++) {
        int delta = min(amount, limit[i]);
        amount -= delta;
        cost += delta * price[i];
    }

    cout.precision(2);
    cout << "Account #: " << id << "\nBill: " << fixed << cost << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}