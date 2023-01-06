#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    double x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    cout.precision(3);
    cout << fixed << hypot(x1 - x2, y1 - y2);
}