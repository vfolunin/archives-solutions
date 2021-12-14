#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int modelCount, damagedCount;
    if (!(cin >> modelCount >> damagedCount))
        return 0;

    vector<int> modelCost(modelCount);
    for (int &cost : modelCost)
        cin >> cost;

    sort(modelCost.rbegin(), modelCost.rend());

    int damagedCost = 0;
    for (int i = 0; i < damagedCount; i++)
        damagedCost += modelCost[i];

    cout << damagedCost << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}