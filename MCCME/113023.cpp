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

    int maxValue, maxCount;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (!i || maxValue < value) {
            maxValue = value;
            maxCount = 1;
        } else if (maxValue == value) {
            maxCount++;
        }
    }

    cout << maxValue << " " << maxCount;
}