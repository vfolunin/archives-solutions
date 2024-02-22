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

    double side, height, angle;
    cin >> side >> height >> angle;

    angle *= acos(-1) / 180;
    double diagonal = side * sqrt(2);
    double diagonalHalf = diagonal / 2;
    double res;

    if (angle == 0) {
        res = 0;
    } else if (angle == acos(-1) / 2) {
        res = diagonal * height;
    } else if (diagonalHalf * tan(angle) <= height) {
        double triangleHeight = diagonalHalf / cos(angle);
        res = diagonal * triangleHeight / 2;
    } else {
        double trapezoidHeight = height / sin(angle);
        double smallTriangleHeight = diagonalHalf - height / tan(angle);
        double smallDiagonal = smallTriangleHeight * 2;
        res = (diagonal + smallDiagonal) / 2 * trapezoidHeight;
    }

    cout.precision(3);
    cout << fixed << res;
}