#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int itemCount, maxWeight;
    if (!(cin >> itemCount >> maxWeight))
        return 0;

    vector<int> maxBonus(maxWeight + 1, -1e9);
    maxBonus[0] = 0;

    for (int i = 0; i < itemCount; i++) {
        int bonus, weight;
        cin >> bonus >> weight;
        for (int w = maxWeight; w >= weight; w--)
            if (maxBonus[w - weight] != -1e9)
                maxBonus[w] = max(maxBonus[w], maxBonus[w - weight] + bonus);
    }
    
    cout << *max_element(maxBonus.begin(), maxBonus.end()) << " min.\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}