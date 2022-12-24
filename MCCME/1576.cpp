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

    int capacity, itemCount;
    cin >> capacity >> itemCount;

    vector<int> itemWeight(itemCount);
    for (int &weight : itemWeight)
        cin >> weight;

    sort(itemWeight.begin(), itemWeight.end());

    for (int i = 0; i < itemCount; i++) {
        if (capacity < itemWeight[i]) {
            cout << i;
            return 0;
        }
        capacity -= itemWeight[i];
    }

    cout << itemCount;
}