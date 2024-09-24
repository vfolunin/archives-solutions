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

    vector<int> itemWeights(itemCount);
    for (int &itemWeight : itemWeights)
        cin >> itemWeight;

    vector<int> ways(targetWeight + 1);
    ways[0] = 1;

    for (int weight = 1; weight <= targetWeight; weight++)
        for (int itemWeight : itemWeights)
            if (weight >= itemWeight)
                ways[weight] += ways[weight - itemWeight];

    cout << ways[targetWeight];
}