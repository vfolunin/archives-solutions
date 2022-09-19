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

    int maxValue = -1e9, maxCount = 0;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        if (maxValue < value) {
            maxValue = value;
            maxCount = 1;
        } else if (maxValue == value) {
            maxCount++;
        }
    }

    cout << maxCount;
}