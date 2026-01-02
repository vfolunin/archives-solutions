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

    int maxValue = 0, res = size;
    for (int i = 1; i <= size; i++) {
        int value;
        cin >> value;

        res -= value == i && maxValue < value;
        maxValue = max(maxValue, value);
    }

    cout << res;
}