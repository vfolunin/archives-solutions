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

    vector<int> itemWeights(itemCount);
    for (int &itemWeight : itemWeights)
        cin >> itemWeight;

    vector<int> can(weightLimit + 1);
    can[0] = 1;

    for (int itemWeight : itemWeights)
        for (int weight = weightLimit; weight >= itemWeight; weight--)
            can[weight] |= can[weight - itemWeight];

    int res = weightLimit;
    while (!can[res])
        res--;

    cout << res;
}