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

    int h, w;
    cin >> h >> w;

    int maxValue = 0, maxCount = 0;

    for (int y = 0; y < h; y++) {
        int curValue = 0;

        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;
            curValue = max(curValue, value);
        }

        if (maxValue < curValue) {
            maxValue = curValue;
            maxCount = 1;
        } else if (maxValue == curValue) {
            maxCount++;
        }
    }

    cout << maxCount;
}