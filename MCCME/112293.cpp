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

    int minValue = -1, maxValue = -1;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value > 0 && value % 2 == 0) {
            if (minValue == -1 || minValue > value)
                minValue = value;
            if (maxValue < value)
                maxValue = value;
        }
    }

    cout << minValue << " " << maxValue;
}