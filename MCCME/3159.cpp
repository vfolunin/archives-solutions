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

    int value, minPositive = 1e9;

    while (cin >> value)
        if (value > 0)
            minPositive = min(minPositive, value);

    cout << minPositive;
}