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

    double minValue = 1e100, maxValue = -1e100;

    for (double value; cin >> value; ) {
        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout.precision(2);
    cout << fixed << maxValue - minValue;
}