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

    int total, typed, percent;
    cin >> total >> typed >> percent;

    int continueCost = 100 * (1 + total - typed) + (4 + total) * percent;
    int backspaceCost = 100 * (2 + total - typed) + (4 + total) * (100 - percent);
    int restartCost = 100 * (4 + total);

    if (continueCost < backspaceCost && continueCost < restartCost)
        cout << "continue";
    else if (backspaceCost < continueCost && backspaceCost < restartCost)
        cout << "backspace";
    else
        cout << "restart";
}