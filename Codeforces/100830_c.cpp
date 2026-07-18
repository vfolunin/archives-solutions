#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("colors.in", "r", stdin);
    freopen("colors.out", "w", stdout);

    int size;
    cin >> size;

    int minValue = 2e9, maxValue = -2e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout << maxValue - minValue + 1;
}