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

    int limit;
    cin >> limit;

    vector<int> itemCount(limit + 1, -1);
    itemCount[0] = 0;

    for (int i = 0; i < 5; i++) {
        int itemWeight;
        cin >> itemWeight;

        for (int weight = itemCount.size() - 1; weight >= itemWeight; weight--)
            if (itemCount[weight - itemWeight] != -1)
                itemCount[weight] = max(itemCount[weight], itemCount[weight - itemWeight] + 1);
    }

    cout << *max_element(itemCount.begin(), itemCount.end());
}