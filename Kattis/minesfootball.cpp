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

    int h;
    cin >> h;

    int minValue = 1e9, maxValue = 0, minSum = 1e9, maxSum = 0;
    for (int y = 0; y < h; y++) {
        int w;
        cin >> w;

        int sum = 0;
        for (int x = 0; x < w; x++) {
            int value;
            cin >> value;

            sum += value;
            minValue = min(minValue, value);
            maxValue = max(maxValue, value);
        }

        minSum = min(minSum, sum);
        maxSum = max(maxSum, sum);
    }

    cout << maxValue << "\n" << minValue << "\n" << maxSum << "\n" << minSum;
}