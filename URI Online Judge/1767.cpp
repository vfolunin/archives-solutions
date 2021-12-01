#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int itemCount, maxWeight = 50;
    cin >> itemCount;

    vector<int> maxCost(maxWeight + 1);
    vector<int> count(maxWeight + 1);

    for (int i = 0; i < itemCount; i++) {
        int itemWeight, itemCost;
        cin >> itemCost >> itemWeight;
        for (int w = maxWeight; w >= itemWeight; w--) {
            if (maxCost[w] < maxCost[w - itemWeight] + itemCost) {
                maxCost[w] = maxCost[w - itemWeight] + itemCost;
                count[w] = count[w - itemWeight] + 1;
            }
        }
    }

    int weight = max_element(maxCost.begin(), maxCost.end()) - maxCost.begin();
    cout << maxCost[weight] << " brinquedos\n";
    cout << "Peso: " << weight << " kg\n";
    cout << "sobra(m) " << itemCount - count[weight] << " pacote(s)\n\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}