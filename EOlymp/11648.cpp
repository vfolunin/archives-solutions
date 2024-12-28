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

    int minValue = 2e9, maxValue = -2e9, mode = -2e9;
    unordered_map<int, int> count;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
        count[value]++;
        if (mode == -2e9 || count[mode] < count[value] || count[mode] == count[value] && mode < value)
            mode = value;
    }

    cout << minValue << "\n" << maxValue << "\n" << mode;
}