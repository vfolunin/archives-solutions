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

    int sum = 0, minValue = 1e9;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        minValue = min(minValue, value);
    }

    cout << sum - minValue;
}