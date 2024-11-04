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

    if (size == 1) {
        cout << 0;
        return 0;
    }

    long long minValue = stoll("1" + string((size - 1) / 2, '0') + string(size / 2, '9'));
    long long maxValue = stoll(string(size / 2, '9') + "1" + string((size - 1) / 2, '0'));

    cout << maxValue - minValue;
}