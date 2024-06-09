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

    vector<int> itemWeights(itemCount);
    for (int &weight : itemWeights)
        cin >> weight;

    vector<int> res(weightLimit + 1, -1e9);
    res[0] = 0;

    for (int itemWeight : itemWeights)
        for (int weight = weightLimit; weight >= itemWeight; weight--)
            if (itemWeight <= weight)
                res[weight] = max(res[weight], res[weight - itemWeight] + 1);

    cout << *max_element(res.begin(), res.end());
}