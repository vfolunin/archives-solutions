#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    int size;
    cin >> size;

    if (!size)
        return 0;

    int maxValue = -2e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        maxValue = max(maxValue, value);
    }

    cout << maxValue << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}