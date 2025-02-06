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

    if (itemCount % 2) {
        cout << "No solution";
        return 0;
    }

    vector<int> itemWeights(itemCount);
    int totalWeight = 0;
    for (int &itemWeight : itemWeights) {
        cin >> itemWeight;
        totalWeight += itemWeight;
    }

    if (totalWeight % 2) {
        cout << "No solution";
        return 0;
    }

    vector take(itemCount, vector(itemCount / 2 + 1, vector<char>(totalWeight / 2 + 1, -1)));
    take[0][0][0] = 0;
    take[0][1][itemWeights[0]] = 1;

    for (int i = 1; i < itemCount; i++) {
        for (int count = 0; count <= i && count <= itemCount / 2; count++) {
            for (int weight = 0; weight <= totalWeight / 2; weight++) {
                if (take[i - 1][count][weight] != -1)
                    take[i][count][weight] = 0;
                else if (count && weight >= itemWeights[i] && take[i - 1][count - 1][weight - itemWeights[i]] != -1)
                    take[i][count][weight] = 1;
            }
        }
    }

    if (take.back()[itemCount / 2][totalWeight / 2] == -1) {
        cout << "No solution";
        return 0;
    }
    
    vector<int> a, b;
    for (int i = take.size() - 1, count = itemCount / 2, weight = totalWeight / 2; i >= 0; i--) {
        if (take[i][count][weight]) {
            a.push_back(i);
            count--;
            weight -= itemWeights[i];
        } else {
            b.push_back(i);
        }
    }

    for (int index : a)
        cout << index + 1 << " ";
    cout << "\n";
    for (int index : b)
        cout << index + 1 << " ";
}