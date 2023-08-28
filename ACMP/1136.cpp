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

    int maxValue = 0;

    while (1) {
        int value;
        cin >> value;

        if (!value)
            break;

        maxValue = max(maxValue, value);
    }

    cout << maxValue;
}