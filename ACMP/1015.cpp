#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int mass, percent, deltaCount;
    cin >> mass >> percent >> deltaCount;

    double dryMass = mass * (100.0 - percent) / 100.0;

    for (int i = 0; i < deltaCount; i++) {
        int delta;
        cin >> delta;
        mass += delta;
    }

    cout << mass << " " << (int)round((mass - dryMass) / mass * 100);
}