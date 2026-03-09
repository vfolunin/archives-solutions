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

        value -= value % 2 == 0;

        sum += value;
        minValue = min(minValue, value);
    }

    if (sum % 2 == 0)
        sum -= minValue;

    cout << sum;
}