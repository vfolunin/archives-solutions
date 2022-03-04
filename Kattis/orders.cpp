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

    int itemCount;
    cin >> itemCount;

    vector<int> itemWeights(itemCount);
    for (int &itemWeight : itemWeights)
        cin >> itemWeight;

    vector<int> last(30001, -1);
    last[0] = -3;

    for (int item = 0; item < itemWeights.size(); item++) {
        for (int weight = 0; weight + itemWeights[item] < last.size(); weight++) {
            if (last[weight] == -1)
                continue;
            if (last[weight] == -2 || last[weight + itemWeights[item]] != -1)
                last[weight + itemWeights[item]] = -2;
            else if (last[weight + itemWeights[item]] == -1)
                last[weight + itemWeights[item]] = item;
        }
    }

    int queryCount;
    cin >> queryCount;

    for (int i = 0; i < queryCount; i++) {
        int weight;
        cin >> weight;

        if (last[weight] == -1) {
            cout << "Impossible\n";
        } else if (last[weight] == -2) {
            cout << "Ambiguous\n";
        } else {
            vector<int> items;
            for (; weight; weight -= itemWeights[last[weight]])
                items.push_back(last[weight]);

            sort(items.begin(), items.end());

            for (int item : items)
                cout << item + 1 << " ";
            cout << "\n";
        }
    }
}