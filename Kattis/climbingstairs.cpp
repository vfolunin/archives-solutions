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

    int stepCount, deskFloor, officeFloor;
    cin >> stepCount >> deskFloor >> officeFloor;

    int steps = 0;
    if (deskFloor <= officeFloor)
        steps = officeFloor + officeFloor - deskFloor;
    else
        steps = deskFloor;
    if (steps < stepCount)
        steps = stepCount + (stepCount - steps) % 2;
    steps += deskFloor;

    cout << steps;
}