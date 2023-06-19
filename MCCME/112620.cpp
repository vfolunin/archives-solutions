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

    int weightLimit, itemCount;
    cin >> weightLimit >> itemCount;

    vector<vector<int>> from(itemCount + 1, vector<int>(weightLimit + 1, -1));
    from[0][0] = -2;

    for (int i = 1; i <= itemCount; i++) {
        int itemWeight;
        cin >> itemWeight;

        from[i] = from[i - 1];
        for (int weight = weightLimit; weight >= itemWeight; weight--)
            if (from[i - 1][weight - itemWeight] != -1)
                from[i][weight] = weight - itemWeight;
    }

    int weight = weightLimit;
    while (from[itemCount][weight] == -1)
        weight--;

    cout << weight << "\n";

    vector<int> items;
    for (int i = itemCount; i && weight; weight = from[i][weight], i--)
        if (weight != from[i][weight])
            items.push_back(weight - from[i][weight]);
    sort(items.rbegin(), items.rend());

    for (int itemWeight : items)
        cout << itemWeight << " ";
}