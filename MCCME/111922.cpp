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

    int targetWeight, itemCount;
    cin >> targetWeight >> itemCount;

    vector<int> can(targetWeight + 1);
    can[0] = 1;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight;
        cin >> itemWeight;

        for (int weight = itemWeight; weight < can.size(); weight++)
            can[weight] |= can[weight - itemWeight];
    }

    while (!can[targetWeight])
        targetWeight--;

    cout << targetWeight;
}