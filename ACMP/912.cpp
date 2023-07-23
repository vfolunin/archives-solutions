#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int size;
    cin >> size;

    unordered_map<int, int> count;
    int maxCount = 0, maxValue = 0;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        count[value]++;

        if (maxCount < count[value]) {
            maxCount = count[value];
            maxValue = value;
        } else if (maxCount == count[value]) {
            maxValue = 0;
        }
    }

    cout << maxValue;
}