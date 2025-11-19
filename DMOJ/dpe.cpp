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

    int costLimit = itemCount * 1000;
    vector<long long> minWeight(costLimit + 1, 2e9);
    minWeight[0] = 0;

    for (int item = 0; item < itemCount; item++) {
        int itemWeight, itemPrice;
        cin >> itemWeight >> itemPrice;

        for (int cost = costLimit; cost >= itemPrice; cost--)
            minWeight[cost] = min(minWeight[cost], minWeight[cost - itemPrice] + itemWeight);
    }

    int res = minWeight.size() - 1;
    while (minWeight[res] > weightLimit)
        res--;

    cout << res;
}