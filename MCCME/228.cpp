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

    int maxValue = -1e9, maxIndex = -1;

    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (maxValue < value) {
            maxValue = value;
            maxIndex = i;
        }
    }

    cout << maxIndex + 1;
}