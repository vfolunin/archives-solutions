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

    int minValue, minCount;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (!i || minValue > value) {
            minValue = value;
            minCount = 1;
        } else if (minValue == value) {
            minCount++;
        }
    }

    cout << minValue << "\n" << minCount;
}