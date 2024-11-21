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

    int aSize, bSize;
    cin >> aSize >> bSize;

    double aNum = 0, aDen = 0;
    for (int i = 0; i < aSize; i++) {
        double value, percentage;
        cin >> value >> percentage;

        aNum += percentage / 100 * value;
        aDen += value;
    }

    double bNum = 0, bDen = 0;
    for (int i = 0; i < bSize; i++) {
        double value, percentage;
        cin >> value >> percentage;

        bNum += percentage / 100 * value;
        bDen += value;
    }

    cout << (abs(aNum / aDen - bNum / bDen) < 1e-9 ? "same" : "different");
}