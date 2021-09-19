#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int emptyWeight, fullWeight, coinCount;
    cin >> emptyWeight >> fullWeight >> coinCount;

    int targetWeight = fullWeight - emptyWeight;

    vector<int> minCost(targetWeight + 1, 1e9);
    minCost[0] = 0;

    for (int i = 0; i < coinCount; i++) {
        int cost, weight;
        cin >> cost >> weight;

        for (int w = weight; w < minCost.size(); w++)
            minCost[w] = min(minCost[w], minCost[w - weight] + cost);
    }

    if (minCost[targetWeight] != 1e9)
        cout << "The minimum amount of money in the piggy-bank is " << minCost[targetWeight] << ".\n";
    else
        cout << "This is impossible.\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}