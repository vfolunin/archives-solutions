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

    int itemCount, weightLimit;
    cin >> itemCount >> weightLimit;

    vector<int> weight(itemCount);
    for (int &w : weight)
        cin >> w;

    vector<int> can(weightLimit + 1, 0);
    can[0] = 1;

    for (int i = 0; i < itemCount; i++)
        for (int sum = weightLimit; sum >= weight[i]; sum--)
            can[sum] |= can[sum - weight[i]];

    int res = weightLimit;
    while (!can[res])
        res--;

    cout << res;
}