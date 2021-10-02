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

    int maxValue = 0, maxIndex = -1;
    for (int i = 0; i < 100; i++) {
        int value;
        cin >> value;

        if (maxValue < value) {
            maxValue = value;
            maxIndex = i + 1;
        }
    }

    cout << maxValue << "\n";
    cout << maxIndex << "\n";
}