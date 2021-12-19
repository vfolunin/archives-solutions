#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve(int test) {
    int itemCount, maxWeight;
    cin >> itemCount >> maxWeight;

    vector<int> maxCost(maxWeight + 1);
    for (int i = 0; i < itemCount; i++) {
        int itemCost, itemWeight;
        cin >> itemCost >> itemWeight;
        for (int w = maxWeight; w >= itemWeight; w--)
            maxCost[w] = max(maxCost[w], maxCost[w - itemWeight] + itemCost);
    }

    cout << "Galho " << test << ":\n";
    cout << "Numero total de enfeites: ";
    cout << *max_element(maxCost.begin(), maxCost.end()) << "\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int test = 1; test <= n; test++)
        solve(test);
}