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

    long long sum = 0;
    int evenCount = 0, maxValue = -2e9, max2Value = -2e9;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        evenCount += value % 2 == 0;
        if (maxValue < value) {
            max2Value = maxValue;
            maxValue = value;
        } else if (maxValue > value && max2Value < value) {
            max2Value = value;
        }
    }

    cout << sum << "\n";
    cout << evenCount << "\n";
    cout << maxValue << "\n";
    cout << 1LL * maxValue * max2Value;
}