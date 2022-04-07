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

    int a1, b1, a2, b2, at, bt;
    cin >> a1 >> b1 >> a2 >> b2 >> at >> bt;

    bool can = 0;

    can |= abs(a1) + abs(a1 - a2) <= at &&
        abs(a1) + abs(a1 - a2) + abs(a2 - b1) + abs(b1 - b2) <= bt;

    can |= abs(b1) + abs(b1 - b2) <= bt &&
        abs(b1) + abs(b1 - b2) + abs(b2 - a1) + abs(a1 - a2) <= at;

    can |= abs(b1) + abs(b1 - a1) + abs(a1 - a2) <= at &&
        abs(b1) + abs(b1 - a1) + abs(a1 - a2) + abs(a2 - a1) + abs(a1 - b2) <= bt;

    can |= abs(a1) + abs(a1 - b1) + abs(b1 - b2) <= bt &&
        abs(a1) + abs(a1 - b1) + abs(b1 - b2) + abs(b2 - b1) + abs(b1 - a2) <= at;

    cout << (can ? "possible" : "impossible");
}