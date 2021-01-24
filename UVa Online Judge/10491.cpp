#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

bool solve() {
    double cows, cars, openedDoors;
    if (!(cin >> cows >> cars >> openedDoors))
        return 0;
    double doors = cows + cars;

    double p0 = cows / doors;
    double p01 = cars / (doors - openedDoors - 1);

    double p1 = cars / doors;
    double p11 = (cars - 1) / (doors - openedDoors - 1);

    cout.precision(5);
    cout << fixed << p0 * p01 + p1 * p11 << "\n";
    return 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    while (solve());
}