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

    int size;
    cin >> size;

    vector<int> price(size);
    for (int &value : price)
        cin >> value;

    vector<int> maxCost(size + 1);
    for (int i = 1; i < maxCost.size(); i++)
        for (int j = 1; j <= i; j++)
            maxCost[i] = max(maxCost[i], maxCost[i - j] + price[j - 1]);

    cout << *max_element(maxCost.begin(), maxCost.end());
}