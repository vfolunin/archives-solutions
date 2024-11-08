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

    int minValue = 1e9, maxValue = -1e9;

    for (string s; cin >> s; ) {
        if (s.size() == 10)
            continue;

        int value = stoi(s);

        minValue = min(minValue, value);
        maxValue = max(maxValue, value);
    }

    cout << minValue << " " << maxValue;
}