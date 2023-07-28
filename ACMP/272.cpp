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

    int minValue = 1e9, maxValue = -1e9;
    for (int i = 0, value; cin >> value; i++) {
        if (i % 2 == 0)
            minValue = min(minValue, value);
        else
            maxValue = max(maxValue, value);
    }

    cout << minValue + maxValue;
}