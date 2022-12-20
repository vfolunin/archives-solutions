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

    double x, y;
    cin >> x >> y;

    bool a = y > x * 5 / 3 + 2;
    bool b = y > x * -1.5;
    bool c = hypot(x - 0.5, y - 1) < 2;

    if (a && !b && !c || !a && b && c)
        cout << "TRUE";
    else
        cout << "FALSE";
}