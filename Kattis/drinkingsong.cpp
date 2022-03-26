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

    int bottleCount;
    string drink;
    cin >> bottleCount >> drink;

    for (; bottleCount > 1; bottleCount--) {
        cout << bottleCount << " bottles of " << drink << " on the wall, ";
        cout << bottleCount << " bottles of " << drink << ".\n";
        cout << "Take one down, pass it around, " << bottleCount - 1;
        cout << " bottle" << (bottleCount > 2 ? "s" : "") << " of " << drink << " on the wall.\n\n";
    }

    cout << "1 bottle of " << drink << " on the wall, 1 bottle of " << drink << ".\n";
    cout << "Take it down, pass it around, no more bottles of " << drink << ".\n";
}