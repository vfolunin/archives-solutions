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

    double x, y, w, h;
    cin >> x >> y >> w >> h;

    cout.precision(3);
    cout << fixed << abs(x * y) << " " << abs(x * (h - y)) << " ";
    cout << abs((w - x) * (h - y)) << " " << abs((w - x) * y);
}