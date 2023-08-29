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

    int size, mod;
    cin >> size >> mod;

    long long minValue = 1e18, maxValue = -1e18;
    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        if (value % mod == 0) {
            minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }
    }

    if (minValue <= maxValue)
        cout << minValue << " " << maxValue;
    else
        cout << "NO";
}