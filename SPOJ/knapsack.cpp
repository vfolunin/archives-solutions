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

    vector<int> res(weightLimit + 1);

    for (int i = 0; i < itemCount; i++) {
        int itemWeight, itemPrice;
        cin >> itemWeight >> itemPrice;

        for (int weight = res.size() - 1; weight >= itemWeight; weight--)
            res[weight] = max(res[weight], res[weight - itemWeight] + itemPrice);
    }

    cout << *max_element(res.begin(), res.end());
}