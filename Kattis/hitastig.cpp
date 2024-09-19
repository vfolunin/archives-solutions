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

    long long minValue = 1e18;
    long long maxValue = -1e18;

    for (int i = 0; i < size; i++) {
        long long value;
        cin >> value;

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout << maxValue << " " << minValue;
}