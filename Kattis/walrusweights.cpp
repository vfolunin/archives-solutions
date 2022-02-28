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

    int itemCount;
    cin >> itemCount;

    vector<int> itemWeights(itemCount);
    for (int &itemWeight : itemWeights)
        cin >> itemWeight;

    vector<int> can(2001);
    can[0] = 1;

    for (int itemWeight : itemWeights)
        for (int sum = 2000; sum >= itemWeight; sum--)
            can[sum] |= can[sum - itemWeight];

    int res = 0;
    while (!can[1000 + res] && !can[1000 - res])
        res++;

    cout << (can[1000 + res] ? 1000 + res : 1000 - res);
}