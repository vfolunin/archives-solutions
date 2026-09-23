#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

void solve() {
    int size;
    cin >> size;

    int minValue = 1e9, maxValue = -1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout << maxValue - minValue + 1 << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}