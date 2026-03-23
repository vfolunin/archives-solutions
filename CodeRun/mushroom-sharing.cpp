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

    int size;
    cin >> size;

    int res = 0, minValue = 1e9, maxValue = -1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (i % 2) {
            res -= value;
            maxValue = max(maxValue, value);
        } else {
            res += value;
            minValue = min(minValue, value);
        }
    }

    cout << max(res, res + 2 * (maxValue - minValue));
}