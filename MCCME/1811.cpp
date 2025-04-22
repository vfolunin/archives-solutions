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

    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    double dist = hypot(x1 - x2, y1 - y2);

    if (dist < 5)
        cout << 2;
    else
        cout << (int)ceil(dist / 5);
}