#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int itemCount;
    if (!(cin >> itemCount))
        return 0;

    vector<pair<int, int>> items(itemCount);
    for (int i = 0; i < itemCount; i++) {
        cin >> items[i].first;
        items[i].second = i;
    }

    vector<int> res(itemCount);

    sort(items.rbegin(), items.rend());
    int sum = 0;

    for (auto &[item, index] : items) {
        if (sum <= 0) {
            res[index] = 1;
            sum += item;
        } else {
            res[index] = -1;
            sum -= item;
        }
    }

    if (!sum) {
        cout << "Yes\n";
        for (int i = 0; i < res.size(); i++)
            cout << res[i] << (i + 1 < res.size() ? " " : "\n");
    } else {
        cout << "No\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}