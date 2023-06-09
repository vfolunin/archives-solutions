#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int weightLimit, itemCount;
    cin >> weightLimit >> itemCount;

    vector<int> can(weightLimit + 1);
    can[0] = 1;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight;
        cin >> itemWeight;

        for (int weight = can.size() - 1; weight >= itemWeight; weight--)
            can[weight] |= can[weight - itemWeight];
    }

    int res = weightLimit;
    while (!can[res])
        res--;

    cout << res;
}