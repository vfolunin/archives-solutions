#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

double area(double x1, double y1, double x2, double y2, double x3, double y3) {
    return abs((x1 - x2) * (y1 - y3) - (x1 - x3) * (y1 - y2)) / 2;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    cout << fixed << area(x1, y1, x2, y2, x3, y3);
}