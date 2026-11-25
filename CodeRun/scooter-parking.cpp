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

    int segmentCount;
    cin >> segmentCount;

    map<int, int> deltas;
    for (int i = 0; i < segmentCount; i++) {
        int l, r;
        cin >> l >> r;

        deltas[l]--;
        deltas[r]++;
    }

    int value = 0, minValue = 0, maxValue = 0;
    for (auto &[_, delta] : deltas) {
        value += delta;
        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout << maxValue - minValue << " " << -minValue;
}