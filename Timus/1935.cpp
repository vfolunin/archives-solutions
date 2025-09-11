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

    int sum = 0, maxValue = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        sum += value;
        maxValue = max(maxValue, value);
    }

    cout << sum + maxValue;
}