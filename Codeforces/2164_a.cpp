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

    int minValue = 2e9, maxValue = -2e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    int value;
    cin >> value;

    cout << (minValue <= value && value <= maxValue ? "YES\n" : "NO\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int test = 0; test < testCount; test++)
        solve();
}