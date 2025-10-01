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

    cout << minValue << " " << maxValue << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
        solve();
}