#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int raise() {
    throw 1;
    return 1;
}

int checkZero(int value) {
    return !value && raise();
}

int getPartCount(int metalMass, int barMass, int partMass) {
    int barCount = metalMass / barMass;
    int partCount = barMass / partMass * barCount;
    metalMass -= partCount * partMass;
    try {
        checkZero(partCount);
        partCount += getPartCount(metalMass, barMass, partMass);
    } catch (...) {
    }
    return partCount;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int metalMass, barMass, partMass;
    cin >> metalMass >> barMass >> partMass;

    cout << getPartCount(metalMass, barMass, partMass);
}