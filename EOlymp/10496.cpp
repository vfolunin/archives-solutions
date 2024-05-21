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

    int shapeCount;
    cin >> shapeCount;

    int totalSides = 0;
    for (int i = 0; i < shapeCount; i++) {
        string type;
        double side;
        cin >> type >> side;

        totalSides += type == "Triangle" ? 3 : 4;

        cout.precision(4);
        cout << type << " " << fixed << side << "\n";
        cout << "Perimeter: " << fixed << side * (type == "Triangle" ? 3 : 4) << "\n";
        cout << "Interior angle: " << fixed << (type == "Triangle" ? acos(-1) / 3 : acos(0)) << "\n";
    }

    cout << "Total sides: " << totalSides;
}