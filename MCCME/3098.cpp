#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

vector<int> getMinCount(vector<int> &itemWeights) {
    vector<int> minCount(1e4 + 1, 1e9);
    minCount[0] = 0;

    for (int itemWeight : itemWeights)
        for (int weight = minCount.size() - 1; weight >= itemWeight; weight--)
            minCount[weight] = min(minCount[weight], minCount[weight - itemWeight] + 1);

    return minCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int start, aSize;
    cin >> start >> aSize;

    vector<int> a(aSize);
    for (int &value : a)
        cin >> value;

    int bSize;
    cin >> bSize;

    vector<int> b(bSize);
    for (int &value : b)
        cin >> value;

    vector<int> aMinCount = getMinCount(a);
    vector<int> bMinCount = getMinCount(b);

    int res = 1e9;
    for (int weight = start; weight < aMinCount.size(); weight++)
        if (aMinCount[weight] != 1e9)
            res = min(res, bMinCount[weight - start]);

    cout << (res != 1e9 ? res : -1);
}