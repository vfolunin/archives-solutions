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

    double volume;
    cin >> volume;

    if (volume <= 1)
        cout << fixed << 100 * volume;
    else
        cout << fixed << 100 + 100 * (volume - 1) / 3;
}