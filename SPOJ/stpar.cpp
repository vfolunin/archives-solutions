#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int n;
    cin >> n;

    if (!n)
        return 0;

    vector<int> order(n), stack;
    for (int &x : order)
        cin >> x;
    reverse(order.begin(), order.end());

    for (int i = 1; i <= n; ) {
        if (!stack.empty() && stack.back() == i) {
            stack.pop_back();
            i++;
        } else if (!order.empty() && order.back() == i) {
            order.pop_back();
            i++;
        } else if (!order.empty()) {
            stack.push_back(order.back());
            order.pop_back();
        } else {
            cout << "no\n";
            return 1;
        }
    }

    cout << "yes\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}