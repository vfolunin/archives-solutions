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

    long long maxValue, minValue, type;
    cin >> maxValue >> minValue >> type;

    cout << (maxValue - minValue) * 2 << "\n";

    if (type) {
        for (long long value = maxValue; value > minValue; value--)
            cout << value << " ";
        for (long long value = minValue; value < maxValue; value++)
            cout << value << " ";
    }
}