#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int weightLimit, itemCount;
    if (!(cin >> weightLimit >> itemCount))
        return 0;

    vector<int> can(weightLimit + 1);
    can[0] = 1;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight;
        cin >> itemWeight;

        for (int weight = can.size() - 1; weight >= itemWeight; weight--)
            can[weight] |= can[weight - itemWeight];
    }

    int res = can.size() - 1;
    while (!can[res])
        res--;

    cout << "sum:" << res << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}