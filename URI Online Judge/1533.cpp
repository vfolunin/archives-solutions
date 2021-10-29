#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int itemCount;
    cin >> itemCount;

    if (!itemCount)
        return 0;

    vector<pair<int, int>> items(itemCount);
    for (int i = 0; i < itemCount; i++) {
        cin >> items[i].first;
        items[i].second = i;
    }
    sort(items.rbegin(), items.rend());

    cout << items[1].second + 1 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}