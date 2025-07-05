#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    long long value;
    int swapCount;
    cin >> value >> swapCount;

    if (!value && !swapCount)
        return 0;

    long long minValue = value;
    long long maxValue = value;

    for (int i = 0; i < swapCount; i++) {
        int a, b;
        cin >> a >> b;

        if (a == b)
            continue;

        long long aValue = (value >> a) & 1;
        long long bValue = (value >> b) & 1;

        value &= ~(1LL << a);
        value &= ~(1LL << b);

        value |= (aValue << b);
        value |= (bValue << a);

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout << value << " " << maxValue << " " << minValue << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}