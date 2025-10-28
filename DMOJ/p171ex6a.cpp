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

    double maxValue = -1e9;
    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        maxValue = max(maxValue, value);
    }

    cout.precision(4);
    cout << fixed << maxValue;
}