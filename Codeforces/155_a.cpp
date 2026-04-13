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

    int size, minValue;
    cin >> size >> minValue;

    int maxValue = minValue, res = 0;
    for (int i = 1; i < size; i++) {
        int value;
        cin >> value;

        res += value < minValue || value > maxValue;
        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout << res;
}