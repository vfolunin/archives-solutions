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

    int maxValue = 0;
    vector<int> maxIndexes;

    for (int y = 0; y < h; y++) {
        int curValue = 0;

        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;
            curValue = max(curValue, value);
        }

        if (maxValue < curValue) {
            maxValue = curValue;
            maxIndexes = { y };
        } else if (maxValue == curValue) {
            maxIndexes.push_back(y);
        }
    }

    cout << maxIndexes.size() << "\n";
    for (int index : maxIndexes)
        cout << index << " ";
}