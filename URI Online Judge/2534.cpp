#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int itemCount, queryCount;
    if (!(cin >> itemCount >> queryCount))
        return 0;

    vector<int> items(itemCount);
    for (int &item : items)
        cin >> item;
    sort(items.rbegin(), items.rend());

    for (int i = 0; i < queryCount; i++) {
        int index;
        cin >> index;
        cout << items[index - 1] << "\n";
    }
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}