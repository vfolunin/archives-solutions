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

    vector<long long> maxCost(weightLimit + 1);
    for (int item = 0; item < itemCount; item++) {
        int itemWeight, itemPrice;
        cin >> itemWeight >> itemPrice;

        for (int weight = weightLimit; weight >= itemWeight; weight--)
            maxCost[weight] = max(maxCost[weight], maxCost[weight - itemWeight] + itemPrice);
    }

    cout << *max_element(maxCost.begin(), maxCost.end());
}