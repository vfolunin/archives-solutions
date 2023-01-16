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

    int minValue = 2e9, maxValue = 0, value;
    bool found = 0;

    while (cin >> value) {
        if (value % 2 || value <= 0)
            continue;

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
        found = 1;
    }

    if (found)
        cout << minValue << " " << maxValue;
    else
        cout << 0;
}