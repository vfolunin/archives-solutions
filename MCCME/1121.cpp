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

    vector<int> res(weightLimit + 1, 1e9);
    res[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int itemWeight;
        cin >> itemWeight;

        for (int weight = res.size() - 1; weight >= itemWeight; weight--)
            res[weight] = min(res[weight], res[weight - itemWeight] + 1);
    }

    cout << (res[weightLimit] != 1e9 ? res[weightLimit] : 0);
}