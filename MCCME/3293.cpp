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

    long long res = 0;
    int maxValue = 0;
    for (int i = 0; i < size; i++) {
        int value;
        cin >> value;

        if (value)
            res += value + 1;
        maxValue = max(maxValue, value);
    }

    res -= maxValue + 1;

    cout << res;
}