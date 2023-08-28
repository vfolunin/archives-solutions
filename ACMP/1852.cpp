#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int binPow(int x, int p) {
    if (!p)
        return 1;
    if (p % 2)
        return binPow(x, p - 1) * x;
    int r = binPow(x, p / 2);
    return r * r;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int value, size;
    cin >> value >> size;

    int minValue = value, maxValue = value;
    for (int i = 0; i < size; i++) {
        value = binPow(value % 10, 5) * 20 + value / 10;
        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout << minValue << " " << maxValue;
}