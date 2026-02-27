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

    int maxValue = -1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        maxValue = max(maxValue, value);
    }

    cout << maxValue << "\n";
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int testCount;
    cin >> testCount;

    for (int i = 0; i < testCount; i++)
        solve();
}