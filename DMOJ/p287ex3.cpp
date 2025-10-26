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

    double minValue = 1e9;
    for (int i = 0; i < size; i++) {
        double value;
        cin >> value;

        minValue = min(minValue, value);
    }

    cout.precision(2);
    cout << fixed << minValue;
}