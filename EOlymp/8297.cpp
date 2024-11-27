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

    int size;
    cin >> size;

    vector<int> segmentCount = { 6, 2, 5, 5, 4, 5, 6, 3, 7, 6 };
    vector<string> minValue(size + 1, string(size, '9'));
    minValue[0] = "";

    for (int size = 1; size < minValue.size(); size++) {
        for (int digit = 0; digit <= 9; digit++) {
            if (size < segmentCount[digit])
                continue;

            string candidate = minValue[size - segmentCount[digit]] + string(1, digit + '0');
            if (candidate[0] == '0')
                continue;

            if (minValue[size].size() > candidate.size() || minValue[size].size() == candidate.size() &&
                minValue[size] > candidate)
                minValue[size] = candidate;
        }
    }

    string maxValue = (size % 2 ? "7" : "1") + string(size / 2 - 1, '1');

    cout << minValue[size] << " " << maxValue;
}