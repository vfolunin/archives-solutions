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

    int minValue, maxValue;

    for (int i = 0; 1; i++) {
        int value;
        cin >> value;

        if (!value)
            break;

        if (!i || minValue > value)
            minValue = value;
        if (!i || maxValue < value)
            maxValue = value;
    }

    cout << minValue << " " << maxValue;
}